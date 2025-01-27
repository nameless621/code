#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Souvenir
//    https://atcoder.jp/contests/abc286/tasks/abc286_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> S[i];

    int INF = INT_MAX / 2;
    vector<vector<int>> dp(N, vector<int>(N, INF));
    vector<vector<long long>> sum(N, vector<long long>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'Y') {
                dp[i][j] = 1;
                sum[i][j] = A[i] + A[j];
            }
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    sum[i][j] = sum[i][k] + sum[k][j] - A[k];
                }
                if(dp[i][j] == dp[i][k] + dp[k][j]) {
                    sum[i][j] = max(sum[i][j], sum[i][k] + sum[k][j] - A[k]);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int S, T;
        cin >> S >> T;
        S--; T--;
        if(dp[S][T] == INF) cout << "Impossible" << endl;
        else cout << dp[S][T] << " " << sum[S][T] << endl;
    }
}