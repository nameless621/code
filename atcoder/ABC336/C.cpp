#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Even Digits
//    https://atcoder.jp/contests/abc336/tasks/abc336_c



string bn(long long x, long long n) {
    if(x == 0) return "0";
    string s = "";
    string t = "02468";
    while(x) {
        s = t[x % n] + s;
        x /= n;
    }
    return s;
}

int main() {
    long long N;
    cin >> N;

    string res = bn(N-1, 5);
    cout << res << endl;
}