#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Nine
//    https://atcoder.jp/contests/abc309/tasks/abc309_a



int main() {
    int A, B;
    cin >> A >> B;

    if(A % 3 && A + 1 == B) cout << "Yes" << endl;
    else cout << "No" << endl;
}