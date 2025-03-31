#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Right Triangle
//    https://atcoder.jp/contests/abc362/tasks/abc362_b



int f(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    int x[3], y[3];
    for(int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    int a = f(x[0], y[0], x[1], y[1]);
    int b = f(x[1], y[1], x[2], y[2]);
    int c = f(x[2], y[2], x[0], y[0]);

    if(a + b == c || b + c == a || c + a == b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}