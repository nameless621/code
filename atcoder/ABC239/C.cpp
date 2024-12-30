#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Knight Fork 
//    https://atcoder.jp/contests/abc239/tasks/abc239_c



int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    bool ok = false;
    for(int i = x1 - 5; i <= x1 + 5; i++) {
        for(int j = y1 - 5; j <= y1 + 5; j++) {
            int D1 = (i - x1) * (i - x1) + (j - y1) * (j - y1);
            int D2 = (i - x2) * (i - x2) + (j - y2) * (j - y2);
            if(D1 == 5 && D2 == 5) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}