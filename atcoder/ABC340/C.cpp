#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Divide and Divide
//    https://atcoder.jp/contests/abc340/tasks/abc340_c



int main() {
    long long N;
    cin >> N;

    map<long long, long long> memo;
    auto f = [&](auto f, long long x) -> long long {
        if(x <= 1) return 0;
        if(memo.count(x)) return memo[x];
        return memo[x] += x + f(f, x / 2) + f(f, (x + 2 - 1) / 2);
    };

    cout << f(f, N) << endl;
}