#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Flavors
//    https://atcoder.jp/contests/abc315/tasks/abc315_c



int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].second >> P[i].first;
    }

    sort(P.rbegin(), P.rend());
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(P[0].second != P[i].second) {
            ans = max(ans, P[0].first + P[i].first);
        }
        else {
            ans = max(ans, P[0].first + P[i].first / 2);
        }
    }

    cout << ans << endl;
}