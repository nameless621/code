#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Seismic magnitude scales
//    https://atcoder.jp/contests/abc221/tasks/abc221_a



int main() {
    int A, B;
    cin >> A >> B;
    A -= B;
    int ans = 1;
    while(A--) ans *= 32;
    cout << ans << endl;
}