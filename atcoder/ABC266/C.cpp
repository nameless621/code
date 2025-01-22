#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Convex Quadrilateral
//    https://atcoder.jp/contests/abc266/tasks/abc266_c



struct P {
    int x, y;
};

int check(P a, P b, P c) {
    int abx = b.x - a.x;
    int aby = b.y - a.y;
    int bcx = c.x - b.x;
    int bcy = c.y - b.y;
    return abx * bcy - aby * bcx;
}

int main() {
    P A, B, C, D;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    int c1 = check(A, B, C);
    int c2 = check(B, C, D);
    int c3 = check(C, D, A);
    int c4 = check(D, A, B);

    if ((c1 > 0 && c2 > 0 && c3 > 0 && c4 > 0) ||(c1 < 0 && c2 < 0 && c3 < 0 && c4 < 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}