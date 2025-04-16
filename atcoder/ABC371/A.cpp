#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Jiro
//    https://atcoder.jp/contests/abc371/tasks/abc371_a



int main() {
    char AB, AC, BC;
    cin >> AB >> AC >> BC;

    if(AB != AC) cout << 'A' << endl;
    else if(AB == BC) cout << 'B' << endl;
    else cout << 'C' << endl;
}