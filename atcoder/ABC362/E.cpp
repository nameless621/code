#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Count Arithmetic Subsequences
//    https://atcoder.jp/contests/abc362/tasks/abc362_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    mint dp[81][81][81];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            dp[j][i][2] = 1;
        }
        for(int j = 0; j < i; j++) {
            for(int k = 2; k < N; k++) {
                for(int l = i+1; l < N; l++) {
                    if(A[i] - A[j] != A[l] - A[i]) continue;
                    dp[i][l][k+1] += dp[j][i][k];
                }
            }
        }
    }

    cout << N << " ";
    for(int k = 2; k <= N; k++) {
        mint ret = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                ret += dp[i][j][k];
            }
        }
        cout << ret.val() << " ";
    }
    cout << endl;
}