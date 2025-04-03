#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - AtCoder Janken 3
//    https://atcoder.jp/contests/abc365/tasks/abc365_d



int main() {
    int N;
    string  S;
    cin >> N >> S;

    vector<int> dp(3);

    for(int i = 0; i < N; i++) {
        vector<int> p(3);
        swap(dp, p);
        for(int j = 0; j < 3; j++) {
            if(S[i] == 'R') {
                if(j != 0) dp[0] = max(dp[0], p[j]);
                if(j != 1) dp[1] = max(dp[1], p[j] + 1);
            }
            if(S[i] == 'P') {
                if(j != 1) dp[1] = max(dp[1], p[j]);
                if(j != 2) dp[2] = max(dp[2], p[j] + 1);
            }
            if(S[i] == 'S') {
                if(j != 2) dp[2] = max(dp[2], p[j]);
                if(j != 0) dp[0] = max(dp[0], p[j] + 1);
            }
        }
    }

    cout << max({dp[0], dp[1], dp[2]}) << endl;
}