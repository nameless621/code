#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Minimize Abs 1
//    https://atcoder.jp/contests/abc330/tasks/abc330_b



int main() {
    int N, L, R;
    cin >> N >> L >> R;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++) {
        int res = -1;
        if(A[i] < L) res = L;
        else if(R < A[i]) res = R;
        else res = A[i];
        cout << res << (i != N-1 ? " " : "\n");
    }
}