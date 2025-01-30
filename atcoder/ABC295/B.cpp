#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Bombs
//    https://atcoder.jp/contests/abc295/tasks/abc295_b



int main() {
    int R, C;
    cin >> R >> C;

    vector<string> B(R);
    for(int i = 0; i < R; i++) cin >> B[i];

    auto upd = [&](int x, int y, int e) {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                int Mdist = abs(x - i) + abs(y - j);
                if(Mdist <= e && !isdigit(B[i][j])) B[i][j] = '.';
            }
        }
    };

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!isdigit(B[i][j])) continue;
            int x = B[i][j] - '0';
            B[i][j] = '.';
            upd(i, j, x);
        }
    }

    for(int i = 0; i < R; i++) cout << B[i] << endl;
}