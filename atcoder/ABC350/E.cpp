#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Toward 0
//    https://atcoder.jp/contests/abc350/tasks/abc350_e



map<long long, double> memo;
double f(long long N, int A, int X, int Y) {
    if(N == 0) return 0;
    if(memo.count(N)) return memo[N];

    double res1 = X + f(N / A, A, X, Y);
    double res2 = (double)Y * (6.0 / 5.0);
    for(int b = 2; b <= 6; b++) {
        res2 += f(N / b, A, X, Y) / 5.0;
    }

    return memo[N] += min(res1, res2);
}

int main() {
    long long N;
    int A, X, Y;
    cin >> N >> A >> X >> Y;

    double ans = f(N, A, X, Y);
    cout << fixed << setprecision(12) << ans << endl;
}