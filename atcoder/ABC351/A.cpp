#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - The bottom of the ninth
//    https://atcoder.jp/contests/abc351/tasks/abc351_a



int main() {
    int A = 0, B = 0;

    for(int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        A += x;
    }
    for(int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        B += x;
    }

    cout << A - B + 1 << endl;
}