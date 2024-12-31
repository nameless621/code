#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - FG operation
//    https://atcoder.jp/contests/abc220/tasks/abc220_d



using mint = modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<mint> dp(10);
    dp[A[0]] = 1;
    for(int i = 1; i < N; i++) {
        vector<mint> p(10);
        swap(dp, p);
        for(int j = 0; j < 10; j++) {
            int F = (A[i] + j) % 10;
            int G = (A[i] * j) % 10;
            dp[F] += p[j];
            dp[G] += p[j];
        }
    }

    for(int i = 0; i < 10; i++) {
        cout << dp[i].val() << endl;
    }
}