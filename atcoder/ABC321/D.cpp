#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Set Menu 
//    https://atcoder.jp/contests/abc321/tasks/abc321_d



int main() {
    int N, M, P;
    cin >> N >> M >> P;

    vector<long long> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(B.begin(), B.end());
    vector<long long> S(M + 1);
    for(int i = 0; i < M; i++) {
        S[i+1] = S[i] + B[i];
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        int res = lower_bound(B.begin(), B.end(), P - A[i]) - B.begin();
        ans += A[i] * res + S[res] + (long long)P * (M - res);
    }

    cout << ans << endl;
}