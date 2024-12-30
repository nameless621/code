#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Edge Checker
//    https://atcoder.jp/contests/abc240/tasks/abc240_a



int main() {
    int a, b;
    cin >> a >> b;
    if(b - a == 1 || (a == 1 && b == 10)) cout << "Yes" << endl;
    else cout << "No" << endl;
}