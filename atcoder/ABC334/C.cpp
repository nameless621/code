#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Socks 2
//    https://atcoder.jp/contests/abc334/tasks/abc334_c



int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(K);
    for(int i = 0; i < K; i++) cin >> A[i];

    if(K & 1) {
        vector<long long> L(K);
        for(int i = 0; i+1 < K; i += 2) {
            L[i+1] = abs(A[i] - A[i+1]);
        }

        for(int i = 0; i+1 < K; i++) {
            L[i+1] += L[i];
        }

        vector<long long> R(K);
        for(int i = K-1; i-1 >= 0; i -= 2) {
            R[i] = abs(A[i] - A[i-1]);
        }

        for(int i = 0; i+1 < K; i++) {
            R[i+1] += R[i];
        }

        long long ans = LLONG_MAX / 2;
        for(int i = 0; i < K; i++) {
            ans = min(ans, L[i] + (R[K-1] - R[i]));
        }

        cout << ans << endl;
    }
    else {
        long long ans = 0;
        for(int i = 0; i < K; i += 2) {
            ans += abs(A[i] - A[i+1]);
        }
        cout << ans << endl;
    }
    
}