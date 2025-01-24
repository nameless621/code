#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Misjudge the Time
//    https://atcoder.jp/contests/abc278/tasks/abc278_b



int main() {
    int H, W;
    cin >> H >> W;

    while(1) {
        int x = H / 10 * 10 + W / 10;
        int y = H % 10 * 10 + W % 10;
        if(x < 24 && y < 60) break;
        W++;
        if(W == 60) {
            H = (H + 1) % 24;
            W = 0;
        }
    }

    cout << H << " " << W << endl;
}