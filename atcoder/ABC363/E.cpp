#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Sinking Land
//    https://atcoder.jp/contests/abc363/tasks/abc363_e



int main() {
    int H, W, Y;
    cin >> H >> W >> Y;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> q;
    vector<vector<bool>> flag(H, vector<bool>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i == 0 || i == H-1) {
                flag[i][j] = true;
                q.emplace(A[i][j], i, j);
            }
            else if(j == 0 || j == W-1) {
                flag[i][j] = true;
                q.emplace(A[i][j], i, j);
            }
        }
    }

    int ret = H * W;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for(int now = 1; now <= Y; now++) {
        while(!q.empty()) {
            auto[h, x, y] = q.top();
            if(h > now) break;
            ret--;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if(i < 0 || i >= H || j < 0 || j >= W) continue;
                if(flag[i][j]) continue;
                flag[i][j] = true;
                q.emplace(A[i][j], i, j);
            }
        }

        cout << ret << endl;
    }
}