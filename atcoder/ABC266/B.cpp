#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Modulo Number
//    https://atcoder.jp/contests/abc266/tasks/abc266_b



int main() {
    long long N;
    cin >> N;

    long long mod = 998244353;
    N %= mod;
    if(N < 0) N += mod;
    cout << N << endl;
}