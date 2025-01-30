#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Make Takahashi Happy
//    https://atcoder.jp/contests/abc293/tasks/abc293_c



int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    set<int> s;
    auto dfs = [&](auto dfs, int x, int y) -> void {
        if(x+1 == H && y+1 == W) {
            ans++;
            return;
        }
        s.insert(A[x][y]);
        if(x + 1 < H && !s.count(A[x+1][y])) dfs(dfs, x + 1, y);
        if(y + 1 < W && !s.count(A[x][y+1])) dfs(dfs, x, y + 1);
        s.erase(A[x][y]);
    };

    dfs(dfs, 0, 0);
    cout << ans << endl;
}