#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Takahashi Gets Lost
//    https://atcoder.jp/contests/abc341/tasks/abc341_c



int main() {
    int H, W, N;
    string T;
    cin >> H >> W >> N >> T;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    auto check = [&](int x, int y) {
        for(int i = 0; i < N; i++) {
            if(T[i] == 'L') y--;
            if(T[i] == 'R') y++;
            if(T[i] == 'U') x--;
            if(T[i] == 'D') x++;
            if(S[x][y] == '#') return false; 
        }
        return true;
    };

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') continue;
            if(check(i, j)) ans++;
        }
    }

    cout << ans << endl;
}