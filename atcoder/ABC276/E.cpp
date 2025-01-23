#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Round Trip
//    https://atcoder.jp/contests/abc276/tasks/abc276_e



int P(int w, int i, int j) { return i * w + j; }
bool check(int i, int j, int H, int W) { return (i < 0 || i >= H || j < 0 || j >= W); }
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    int si = -1, sj = -1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(C[i][j] == 'S') {
                si = i;
                sj = j;
            }
        }
    }

    dsu uf(H * W);
    queue<pair<int, int>> q;
    vector ok(H, vector<bool>(W));
    for(int k = 0; k < 4; k++) {
        int i = si + dx[k];
        int j = sj + dy[k];
        if(check(i, j, H, W) || C[i][j] == '#') continue;
        ok[i][j] = true;
        q.emplace(i, j);
    }

    while(!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            if(check(i, j, H, W) || C[i][j] != '.') continue;
            uf.merge(P(W, x, y), P(W, i, j));
            if(ok[i][j]) continue;
            ok[i][j] = true;
            q.emplace(i, j);
        }
    }

    bool res = false;
    for(int i = 0; i < 4; i++) {
        int x1 = si + dx[i];
        int y1 = sj + dy[i];
        if(check(x1, y1, H, W)) continue;
        for(int j = i + 1; j < 4; j++) {
            int x2 = si + dx[j];
            int y2 = sj + dy[j];
            if(check(x2, y2, H, W)) continue;   
            if(uf.same(P(W, x1, y1), P(W, x2, y2))) {
                res = true;
            }
        }
    }

    cout << (res ? "Yes" : "No") << endl;
}