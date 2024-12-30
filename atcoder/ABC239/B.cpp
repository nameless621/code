#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Integer Division
//    https://atcoder.jp/contests/abc239/tasks/abc239_b



int main() {
    long long X;
    cin >> X;
    if(X >= 0) {
        cout << X / 10 << endl;
    }
    else {
        X = -X;
        cout << -((X + 10 - 1) / 10) << endl;
    }
}