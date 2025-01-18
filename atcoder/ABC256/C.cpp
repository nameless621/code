#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Filling 3x3 array
//    https://atcoder.jp/contests/abc256/tasks/abc256_c



int main() {
    int x[3], y[3];
    for(int i = 0; i < 3; i++) cin >> x[i];
    for(int i = 0; i < 3; i++) cin >> y[i];

    int ans = 0;
    for(int a = 1; a <= 30; a++) {
        for(int b = 1; b <= 30; b++) {
            for(int d = 1; d <= 30; d++) {
                for(int e = 1; e <= 30; e++) {
                    int c = x[0] - a - b;
                    int f = x[1] - d - e;
                    int g = y[0] - a - d;
                    int h = y[1] - b - e;
                    int i = y[2] - c - f;
                    if(min({c,f,g,h,i}) > 0 && g + h + i == x[2]) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}