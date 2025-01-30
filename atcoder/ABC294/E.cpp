#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - 2xN Grid
//    https://atcoder.jp/contests/abc294/tasks/abc294_e



int main() {
    long long L;
    int N1, N2;
    cin >> L >> N1 >> N2;

    vector<pair<int, long long>> p1, p2;
    auto read = [&](int N, auto& p) {
        for(int i = 0; i < N; i++) {
            long long v, l;
            cin >> v >> l;
            p.emplace_back(v, l);
        }
    };
    
    read(N1, p1);
    read(N2, p2);

    long long ans = 0;
    long long x1 = 0, y1 = p1[0].second, x2 = 0, y2 = p2[0].second;
    int i = 0, j = 0, col1 = p1[0].first, col2 = p2[0].first;
    while(i < N1 && j < N2) {
        if(col1 == col2) {
            ans += max(0ll, (min(y1, y2) - max(x1, x2)));
        }
        if(y1 < y2) {
            i++;
            x1 = y1;
            y1 += p1[i].second;
            col1 = p1[i].first;
        }
        else if(y1 > y2) {
            j++;
            x2 = y2;
            y2 += p2[j].second;
            col2 = p2[j].first;
        }
        else {
            i++; j++;
            x1 = y1;
            y1 += p1[i].second;
            col1 = p1[i].first;
            x2 = y2;
            y2 += p2[j].second;
            col2 = p2[j].first;
        }
    }

    cout << ans << endl;
}