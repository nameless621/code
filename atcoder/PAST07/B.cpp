#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - 蒸気圧
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_b



int main() {
    double A, B, C;
    cin >> A >> B >> C;
    
    while(A > B * C) A--;
    cout << fixed << setprecision(12) << A / B << endl;
}