#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Count Bracket Sequences
//    https://atcoder.jp/contests/abc312/tasks/abc312_d



int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<vector<mint>> dp(N+1, vector<mint>(N+1));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            if(S[i] == '(' && j+1 <= N) {
                dp[i+1][j+1] += dp[i][j];
            }
            if(S[i] == ')' && j-1 >= 0) {
                dp[i+1][j-1] += dp[i][j];
            }
            if(S[i] == '?') {
                if(j+1 <= N) dp[i+1][j+1] += dp[i][j];
                if(j-1 >= 0) dp[i+1][j-1] += dp[i][j];
            }
        }
    }

    cout << dp[N][0].val() << endl;
}