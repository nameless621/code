#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Grid Ice Floor
//    https://atcoder.jp/contests/abc311/tasks/abc311_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector ok(N, vector(M, vector<bool>(4)));
    ok[1][1][1] = true;
    ok[1][1][2] = true;
    queue<tuple<int, int, int>> q;
    q.emplace(1, 1, 1);
    q.emplace(1, 1, 2);
    while(!q.empty()) {
        auto[x, y, t] = q.front();
        q.pop();
        int i = x + dx[t];
        int j = y + dy[t];
        if(S[i][j] == '#') {
            for(int k = 0; k < 4; k++) {
                i = x + dx[k];
                j = y + dy[k];
                if(S[i][j] == '#' || ok[i][j][k]) continue;
                ok[i][j][k] = true;
                q.emplace(i, j, k);
            }
        }
        else {
            ok[i][j][t] = true;
            q.emplace(i, j, t);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            bool flag = false;
            for(int k = 0; k < 4; k++) {
                if(ok[i][j][k]) flag = true;
            }
            if(flag) ans++;
        }
    }

    cout << ans << endl;
}