#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - 10yen Stamp
//    https://atcoder.jp/contests/abc233/tasks/abc233_a



int main() {
    int X, Y;
    cin >> X >> Y;
    
    if(X >= Y) {
        cout << 0 << endl;
    }
    else {
        int rem = Y - X;
        cout << (rem + 10 - 1) / 10 << endl;
    }
}