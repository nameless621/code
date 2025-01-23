#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Sugoroku 4
//    https://atcoder.jp/contests/abc275/tasks/abc275_e



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    mint P = mint(1) / M;
    vector<mint> dp(N + 1);
    dp[0] = 1;
    for(int i = 0; i < K; i++) {
        vector<mint> p(N + 1);
        swap(dp, p);
        for(int j = 0; j <= N; j++) {
            if(j == N) {
                dp[j] += p[j];
                continue;
            }
            for(int l = 1; l <= M; l++) {
                int nex = j + l;
                if(nex > N) nex = N - (nex - N);
                dp[nex] += p[j] * P;
            }
        }
    }

    cout << dp[N].val() << endl;
}