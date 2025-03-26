#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Alphabet Tiles
//    https://atcoder.jp/contests/abc358/tasks/abc358_e



const int MAX_K = 1000;
mint comb[MAX_K + 1][MAX_K + 1];
void pascal() {
    for (int i = 0; i <= MAX_K; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

int main() {
    int K;
    cin >> K;

    vector<int> C(26);
    for(int& c : C) cin >> c;

    pascal();
    vector<vector<mint>> dp(27, vector<mint>(K+1));
    dp[0][0] = 1;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j <= K; j++) {
            for(int l = 0; l <= C[i]; l++) {
                if(j + l > K) break;
                dp[i+1][j+l] += dp[i][j] * comb[j+l][l];
            }
        }
    }

    mint ans = 0;
    for(int j = 1; j <= K; j++) {
        ans += dp[26][j];
    }

    cout << ans.val() << endl;
}