#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Digit Sum Divisible
//    https://atcoder.jp/contests/abc336/tasks/abc336_e



long long f(vector<int>& x, int K) {
    int N = x.size();
    vector dp(N+1, vector(K+1, vector(K, vector<long long>(2))));
    dp[0][0][0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            for(int l = 0; l < K; l++) {
                for(int m = 0; m < 2; m++) {
                    if(dp[i][j][l][m] == 0) continue;
                    for(int d = 0; d <= 9; d++) {
                        int nj = j + d, nl = (l * 10 + d) % K, nm = m;
                        if(nj > K) break;
                        if(nm == 0) {
                            if(x[i] < d) continue;
                            if(x[i] > d) nm++;
                        }
                        dp[i+1][nj][nl][nm] += dp[i][j][l][m];
                    }
                }
            }
        }
    }
    return dp[N][K][0][0] + dp[N][K][0][1];
}

int main() {
    long long N;
    cin >> N;

    vector<int> x;
    while(N > 0) {
        x.push_back(N % 10);
        N /= 10;
    }
    reverse(x.begin(), x.end());

    long long ans = 0;
    for(int K = 1; K <= 126; K++) {
        ans += f(x, K);
    }

    cout << ans << endl;
}