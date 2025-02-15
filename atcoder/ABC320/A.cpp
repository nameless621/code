#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Leyland Number
//    https://atcoder.jp/contests/abc320/tasks/abc320_a



int main() {
    long long A, B;
    cin >> A >> B;
    
    long long res = pow(A, B) + pow(B, A);
    cout << res << endl;
}