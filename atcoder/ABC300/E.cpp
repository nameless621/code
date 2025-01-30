#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Dice Product 3
//    https://atcoder.jp/contests/abc300/tasks/abc300_e



int main() {
    long long N;
    cin >> N;

    map<long long, mint> memo;
    auto f = [&](auto f, long long n) -> mint {
        if(n >= N) return (n == N ? 1 : 0);
        if(memo.count(n)) return memo[n];
        mint res = 0;
        for(int i = 2; i <= 6; i++) res += f(f, n * i);
        return memo[n] += res / 5;
    };

    cout << f(f, 1).val() << endl;
}