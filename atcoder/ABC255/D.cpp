#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - ±1 Operation 2
//    https://atcoder.jp/contests/abc255/tasks/abc255_d



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    vector<long long> S(N + 1);
    for(int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }

    while(Q--) {
        long long X;
        cin >> X;
        int L = lower_bound(A.begin(), A.end(), X) - A.begin();
        int R = upper_bound(A.begin(), A.end(), X) - A.begin();
        long long res = 0;
        res += S[N] - S[R] - X * (N - R);
        res += X * L - S[L];
        cout << res << endl;
    }
}