#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Who Ate the Cake? 
//    https://atcoder.jp/contests/abc355/tasks/abc355_a



int main() {
    int A, B;
    cin >> A >> B;
    
    if(A == B) cout << -1 << endl;
    else cout << 6 - A - B << endl;
}