#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Pawn on a Grid
//    https://atcoder.jp/contests/abc280/tasks/abc280_a



int main() {
    int H, W;
    cin >> H >> W;
    
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') ans++;
        }
    }

    cout << ans << endl;
}