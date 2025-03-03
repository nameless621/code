#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Pyramid
//    https://atcoder.jp/contests/abc336/tasks/abc336_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> L(N);
    L[0] = 1;
    for(int i = 1; i < N; i++) {
        L[i] = min(A[i], L[i-1] + 1);
    }

    vector<int> R(N);
    R[N-1] = 1;
    for(int i = N-2; i >= 0; i--) {
        R[i] = min(A[i], R[i+1] + 1);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, min(L[i], R[i]));
    }

    cout << ans << endl;
}