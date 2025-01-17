#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - FizzBuzz Sum Hard
//    https://atcoder.jp/contests/abc253/tasks/abc253_d



long long sum(long long a, long long d, long long n) {
    long long ret = (2 * a + d * (n - 1)) * n / 2;
    return ret;
}

int main() {
    long long N, A, B;
    cin >> N >> A >> B;

    long long ans = N * (N + 1) / 2;
    long long L = lcm(A, B);
    ans = ans - sum(A, A, N / A) - sum(B, B, N / B) + sum(L, L, N / L);
    cout << ans << endl;
}