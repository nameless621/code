#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Between Two Arrays
//    https://atcoder.jp/contests/abc222/tasks/abc222_d



int main() {
    int N;
    cin >> N;
    
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    int M = 3001;
    vector<vector<mint>> DP(N + 1, vector<mint>(M + 1));
    DP[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            DP[i][j + 1] += DP[i][j];
        }
        for(int j = A[i]; j <= B[i]; j++) {
            DP[i + 1][j] = DP[i][j];
        }
    }

    mint ans = 0;
    for(int j = 0; j <= M; j++) ans += DP[N][j];
    cout << ans.val() << endl;
}