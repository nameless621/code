#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Horizon
//    https://atcoder.jp/contests/abc239/tasks/abc239_a



int main() {
    double H;
    cin >> H;

    double ans = sqrt(H * (12800000 + H));
    cout << fixed << setprecision(12) << ans << endl;
}