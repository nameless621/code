#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - RANDOM
//    https://atcoder.jp/contests/abc279/tasks/abc279_c



vector<string> rot(vector<string> S, int H, int W) {
    vector<string> res(W, string(H, '.'));
    for(int j = 0; j < W; j++) {
        for(int i = 0; i < H; i++) {
            res[j][i] = S[i][j];
        }
    }
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H), T(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    for(int i = 0; i < H; i++) cin >> T[i];

    auto x = rot(S, H, W);
    auto y = rot(T, H, W);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << (x == y ? "Yes" : "No") << endl;
}