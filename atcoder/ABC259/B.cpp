#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Counterclockwise Rotation
//    https://atcoder.jp/contests/abc259/tasks/abc259_b



int main() {
    double A, B, D;
    cin >> A >> B >> D;
    double R = D * M_PI / 180.0;
    double X = A * cos(R) - B * sin(R);
    double Y = A * sin(R) + B * cos(R);
    cout << fixed << setprecision(12) << X << " " << Y << endl;
}
