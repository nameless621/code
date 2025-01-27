#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Edge Checker 2
//    https://atcoder.jp/contests/abc285/tasks/abc285_a



int main() {
    int a, b;
    cin >> a >> b;

    if(a * 2 == b || a * 2 + 1 == b) cout << "Yes" << endl;
    else cout << "No" << endl;
}