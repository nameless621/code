#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Yet Another Recursive Function
//    https://atcoder.jp/contests/abc275/tasks/abc275_d



int main() {
    long long N;
    cin >> N;

    map<long long, long long> memo;
    auto f = [&](auto f, long long x) -> long long {
        if(x == 0) return 1;
        if(memo.count(x)) return memo[x];
        return memo[x] += f(f, x / 2) + f(f, x / 3);
    };

    cout << f(f, N) << endl;
}