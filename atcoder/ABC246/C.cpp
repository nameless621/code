#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Coupon
//    https://atcoder.jp/contests/abc246/tasks/abc246_c



int main() {
    int N, K, X;
    cin >> N >> K >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        int d = A[i] / X;
        if(d < K) {
            A[i] -= d * X;
            K -= d;
        }
        else {
            A[i] -= X * K;
            K = 0;
            break;
        }
    }

    sort(A.rbegin(), A.rend());
    for(int i = 0; i < min(N, K); i++) {
        A[i] = max(0, A[i] - X);
    }

    long long sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
    }

    cout << sum << endl;
}