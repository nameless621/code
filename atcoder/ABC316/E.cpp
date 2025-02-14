#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Avoid Eye Contact
//    https://atcoder.jp/contests/abc317/tasks/abc317_e



int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void func(int H, int W, int x, int y, int t, auto& A, auto& NG) {
    while(1) {
        x += dx[t];
        y += dy[t];
        if(x < 0 || x >= H || y < 0 || y >= W) return;
        if(A[x][y] != '.') return;
        NG[x][y] = true;
    }
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    int si = -1, sj = -1, gi = -1, gj = -1;
    vector<vector<bool>> NG(H, vector<bool>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if(A[i][j] == 'G') {
                gi = i;
                gj = j;
            }
            if(A[i][j] == '>') func(H, W, i, j, 0, A, NG);
            if(A[i][j] == 'v') func(H, W, i, j, 1, A, NG);
            if(A[i][j] == '<') func(H, W, i, j, 2, A, NG);
            if(A[i][j] == '^') func(H, W, i, j, 3, A, NG);
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    dist[si][sj] = 0;
    queue<pair<int, int>> q;
    q.emplace(si, sj);
    while(!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            if(i < 0 || i >= H || j < 0 || j >= W) continue;
            if(A[i][j] != '.' && A[i][j] != 'G') continue;
            if(dist[i][j] != -1 || NG[i][j]) continue;
            dist[i][j] = dist[x][y] + 1;
            q.emplace(i, j);
        }
    }

    cout << dist[gi][gj] << endl;
}