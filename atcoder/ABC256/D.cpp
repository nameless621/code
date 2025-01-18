#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Union of Interval
//    https://atcoder.jp/contests/abc256/tasks/abc256_d



int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> P;
    for(int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        P.emplace_back(L, 0);
        P.emplace_back(R, 1);
    }

    sort(P.begin(), P.end());

    vector<pair<int, int>> ans;
    int L = -1, cnt = 0;
    for(auto[x, t] : P) {
        if(t == 0) {
            cnt++;
            if(L == -1) L = x;
        }
        else {
            cnt--;
            if(cnt == 0) {
                ans.emplace_back(L, x);
                L = -1;
            }
        }
    }

    for(auto[L, R] : ans) {
        cout << L << " " << R << endl;
    }
}