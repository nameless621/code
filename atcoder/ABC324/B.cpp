#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - 3-smooth Numbers
//    https://atcoder.jp/contests/abc324/tasks/abc324_b



int main() {
    long long N;
    cin >> N;

    while(N % 2 == 0) N /= 2;
    while(N % 3 == 0) N /= 3;

    cout << (N == 1 ? "Yes" : "No") << endl;
}