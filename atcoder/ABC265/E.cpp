#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Warp 
//    https://atcoder.jp/contests/abc265/tasks/abc265_e



int main() {
    int N, M;
    cin >> N >> M;
    int dx[3], dy[3];
    for(int i = 0; i < 3; i++) cin >> dx[i] >> dy[i];

    set<pair<long long, long long>> ng;
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        ng.emplace(X, Y);
    } 

    map<pair<long long, long long>, mint> dp;
    dp[{0, 0}] = 1;
    for(int i = 0; i < N; i++) {
        map<pair<long long, long long>, mint> p;
        swap(dp, p);
        for(auto[P, cnt] : p) {
            for(int k = 0; k < 3; k++) {
                long long x = P.first + dx[k];
                long long y = P.second + dy[k];
                if(ng.count({x, y})) continue;
                dp[{x, y}] += cnt;
            }
        }
    }

    mint ans = 0;
    for(auto[P, cnt] : dp) {
        ans += cnt;
    }

    cout << ans.val() << endl;
}