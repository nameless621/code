#include <bits/stdc++.h>
using namespace std;


//    B - Hard Calculation
//    https://atcoder.jp/contests/abc229/tasks/abc229_b



int main() {
    long long A, B;
    cin >> A >> B;

    bool ok = true;
    while(A > 0 && B > 0) {
        int n = A % 10, m = B % 10;
        if(n + m >= 10) {
            ok = false;
            break;
        }
        A /= 10;
        B /= 10;
    }

    if(ok) cout << "Easy" << endl;
    else cout << "Hard" << endl;
}