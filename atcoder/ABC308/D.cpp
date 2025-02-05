#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Snuke Maze
//    https://atcoder.jp/contests/abc308/tasks/abc308_d



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    if(S[0][0] != 's') {
        cout << "No" << endl;
        return 0;
    }

    string T = "snuke";
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<vector<bool>> ok(H, vector<bool>(W));
    ok[0][0] = true;
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    while(!q.empty()) {
        auto[x, y, idx] = q.front();
        q.pop();
        int nex = (idx + 1) % 5;
        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            if(i < 0 || i >= H || j < 0 || j >= W) continue;
            if(ok[i][j] || S[i][j] != T[nex]) continue;
            ok[i][j] = true;
            q.emplace(i, j, nex);
        }
    }

    cout << (ok[H-1][W-1] ? "Yes" : "No") << endl;
}