#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - King Bombee
//    https://atcoder.jp/contests/abc244/tasks/abc244_e



using mint = modint998244353;

int main() {
    int N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X;
    S--; T--; X--;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    // i個目, 直前の整数, 偶奇
    vector dp(K+1, vector(N, vector<mint>(2)));
    dp[0][S][0] = 1;
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            for(int p = 0; p < 2; p++) {
                if(dp[i][j][p] == 0) continue;
                for(int nex : G[j]) {
                    int np = p;
                    if(nex == X) np ^= 1;
                    dp[i+1][nex][np] += dp[i][j][p]; 
                }
            }
        }
    }

    cout << dp[K][T][0].val() << endl;
}