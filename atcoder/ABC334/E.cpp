#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Christmas Color Grid 1
//    https://atcoder.jp/contests/abc334/tasks/abc334_e



int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> func(int H, int W) {
    vector<vector<int>> res(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            res[i][j] = i * W + j;
        }
    }
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    dsu uf(H * W);
    auto P = func(H, W);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.') continue;
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || x >= H || y < 0 || y >= W) continue;
                if(S[x][y] == '.') continue;
                uf.merge(P[i][j], P[x][y]);
            }
        }
    }

    int CC = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.') continue;
            if(uf.leader(P[i][j]) == P[i][j]) CC++;
        }
    }

    long long sum = 0, cnt = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') continue;
            cnt++;
            set<int> L;
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x < 0 || x >= H || y < 0 || y >= W) continue;
                if(S[x][y] == '.') continue;
                L.insert(uf.leader(P[x][y]));
            }
            if(L.size()) sum += CC - (L.size() - 1);
            else sum += CC + 1;
        }
    }

    mint ans = mint(sum) / cnt;
    cout << ans.val() << endl;
}