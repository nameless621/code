#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Grid and Magnet
//    https://atcoder.jp/contests/abc351/tasks/abc351_d



bool check(int i, int j, int H, int W) {
    return (i < 0 || i >= H || j < 0 || j >= W);
}

int main() {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(auto& s : S) cin >> s;
    
    bool flag = false;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.' || S[i][j] == '@') {
                flag = true;
                continue;
            }
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(check(x, y, H, W)) continue;
                if(S[x][y] == '.') S[x][y] = '@';
            }
        }
    }

    vector<vector<bool>> seen(H, vector<bool>(W));
    auto bfs = [&](int si, int sj) {
        int cnt = 0;
        seen[si][sj] = true;
        set<pair<int, int>> st;
        queue<pair<int, int>> q;
        q.emplace(si, sj);
        while(!q.empty()) {
            auto[x, y] = q.front();
            q.pop();
            cnt++;
            for(int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if(check(i, j, H, W) || seen[i][j]) continue;
                if(S[i][j] == '@') {
                    st.emplace(i, j);
                    continue;
                }
                seen[i][j] = true;
                q.emplace(i, j);
            }
        }
        return cnt + st.size();
    };

    int ans = (flag ? 1 : 0);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.' && !seen[i][j]) {
                int res = bfs(i, j);
                ans = max(ans, res);
            }
        }
    }

    cout << ans << endl;
}