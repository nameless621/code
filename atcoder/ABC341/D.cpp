#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Only one of two
//    https://atcoder.jp/contests/abc341/tasks/abc341_d



int main() {
    long long N, M, K;
    cin >> N >> M >> K;

    long long g = lcm(N, M);
    auto check = [&](long long x) {
        long long a = x / N;
        long long b = x / M;
        long long c = x / g;
        return K <= (a + b - 2 * c);
    };

    long long ng = 0, ok = 1e18;
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}