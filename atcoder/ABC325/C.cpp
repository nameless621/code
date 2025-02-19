#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Sensors
//    https://atcoder.jp/contests/abc325/tasks/abc325_c



const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    vector<vector<bool>> ok(H, vector<bool>(W));
    auto func = [&](auto func, int x, int y) -> void {
        ok[x][y] = true;
        for(int k = 0; k < 8; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            if(i < 0 || i >= H || j < 0 || j >= W) continue;
            if(S[i][j] == '.' || ok[i][j]) continue;
            func(func, i, j);
        }
    };

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#' && !ok[i][j]) {
                ans++;
                func(func, i, j);
            }
        }
    }

    cout << ans << endl;
}