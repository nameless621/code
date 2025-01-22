#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Hammer
//    https://atcoder.jp/contests/abc270/tasks/abc270_b



int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if(X < 0) {
        X = -X;
        Y = -Y;
        Z = -Z;
    }

    if(Y < 0 || X < Y) {
        cout << X << endl;
    }
    else if(Z < Y) {
        if(Z < 0) cout << abs(Z) * 2 + X << endl;
        else cout << X << endl;
    }
    else {
        cout << -1 << endl;
    }
}