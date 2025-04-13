#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - K-bonacci
//    https://atcoder.jp/contests/abc401/tasks/abc401_c



int main() {
    int N, K;
    cin >> N >> K;

    int sum = 0, mod = 1e9;
    vector<int> A(N+1);
    for(int i = 0; i < min(N+1, K); i++) {
        A[i] = 1;
        sum++;
    }

    for(int i = K; i <= N; i++) {
        A[i] = sum % mod;
        sum = (sum + A[i]) % mod;
        sum = (sum - A[i-K] + mod) % mod;
    }

    cout << A[N] << endl;
}