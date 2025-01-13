#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Get Closer
//    https://atcoder.jp/contests/abc246/tasks/abc246_b



int main() {
    double A, B;
    cin >> A >> B;

    double d = sqrt(A * A + B * B);
    cout << fixed << setprecision(12) << A / d << endl;
    cout << fixed << setprecision(12) << B / d << endl;
}