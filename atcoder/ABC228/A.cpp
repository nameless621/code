#include <bits/stdc++.h>
using namespace std;


//    A - On and Off
//    https://atcoder.jp/contests/abc228/tasks/abc228_a



int main() {
    int S, T, X;
    cin >> S >> T >> X;

    bool ok = false;
    if(S < T && (S <= X && X < T)) {
        ok = true;
    }
    else if(T < S && (S <= X || X < T)) {
        ok = true;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}