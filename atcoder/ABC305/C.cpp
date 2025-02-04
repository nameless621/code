#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Snuke the Cookie Picker
//    https://atcoder.jp/contests/abc305/tasks/abc305_c



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int a = H, b = 0, c = W, d = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                a = min(a, i);
                b = max(b, i);
                c = min(c, j);
                d = max(d, j);
            }
        }
    }

    for(int i = a; i <= b; i++) {
        for(int j = c; j <= d; j++) {
            if(S[i][j] == '.') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
}