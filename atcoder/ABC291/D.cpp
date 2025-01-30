#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Flip Cards
//    https://atcoder.jp/contests/abc291/tasks/abc291_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<mint> dp(2);
    dp[0] = dp[1] = 1;
    for(int i = 1; i < N; i++) {
        vector<mint> p(2);
        swap(dp, p);
        if(A[i] != A[i-1]) dp[0] += p[0];
        if(A[i] != B[i-1]) dp[0] += p[1];
        if(B[i] != A[i-1]) dp[1] += p[0];
        if(B[i] != B[i-1]) dp[1] += p[1];
    }

    mint ans = dp[0] + dp[1];
    cout << ans.val() << endl;
}