#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Leap Year
//    https://atcoder.jp/contests/abc365/tasks/abc365_a



int main() {
    int Y;
    cin >> Y;

    int ans = 365;
    if((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0)) ans++;

    cout << ans << endl;
}