#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Trophy
//    https://atcoder.jp/contests/abc254/tasks/abc258_d



int main() {
    int N, X;
    cin >> N >> X;

    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    long long ans = LLONG_MAX / 2;
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i] + B[i];
        X--;
        if(X < 0) break;
        long long temp = sum + B[i] * X;
        ans = min(ans, temp);
    }

    cout << ans << endl;
}