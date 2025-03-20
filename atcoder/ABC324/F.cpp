#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Beautiful Path
//    https://atcoder.jp/contests/abc324/tasks/abc324_f



using T = tuple<int, int, int>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<T>> G(N);
    for(int i = 0; i < M; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        u--; v--;
        G[u].emplace_back(v, b, c);
    }

    auto check = [&](double X) {
        double INF = -1e18;
        vector<double> dp(N, INF);
        dp[0] = 0;
        for(int i = 0; i < N; i++) {
            for(auto[j, b, c] : G[i]) {
                double cost = dp[i] + b - X * c;
                if(cost > dp[j]) {
                    dp[j] = cost;
                }
            }
        }
        return dp[N-1] >= 0;
    };
    
    double l = 0, r = 1e18;
    while(abs(l - r) > 1e-10) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(9) << l << endl;
}