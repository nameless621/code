#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Permute K times
//    https://atcoder.jp/contests/abc367/tasks/abc367_e



int main() {
    int N;
    long long K;
    cin >> N >> K;

    int M = 60;
    vector<vector<int>> dp(M, vector<int>(N));
    for(int i = 0; i < N; i++) {
        cin >> dp[0][i];
        dp[0][i]--;
    }

    vector<int> A(N);
    for(int& a : A) cin >> a;

    for(int i = 0; i < M-1; i++) {
        for(int j = 0; j < N; j++) {
            dp[i+1][j] = dp[i][dp[i][j]];
        }
    }

    vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        int idx = i;
        for(int j = 0; j < M; j++) {
            if(K >> j & 1) idx = dp[j][idx];
        }
        ans[i] = A[idx];
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << (i < N-1 ? " " : "\n");
    }
}