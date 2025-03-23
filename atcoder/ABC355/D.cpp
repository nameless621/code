#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Intersecting Intervals
//    https://atcoder.jp/contests/abc355/tasks/abc355_d



int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> P;
    for(int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        P.emplace_back(l, 0);
        P.emplace_back(r, 1);
    }

    sort(P.begin(), P.end());
    long long ans = 0, cnt = 0;
    for(auto[x, t] : P) {
        if(t == 0) cnt++;
        else {
            cnt--;
            ans += cnt;
        }
    }

    cout << ans << endl;
}