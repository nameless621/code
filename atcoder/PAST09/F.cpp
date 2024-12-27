#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    F - 将棋のように
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_f



int main() {
    int A, B;
    cin >> A >> B;
    A--; B--;

    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];

    vector<vector<bool>> ok(9, vector<bool>(9));
    ok[A][B] = true;
    queue<pair<int, int>> q;
    q.emplace(A, B);
    while(!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(S[i][j] == '.') continue;
                int nx = x + i - 1;
                int ny = y + j - 1;
                if(nx < 0 || nx >= 9 || ny < 0 || ny >= 9 || ok[nx][ny]) continue;
                ok[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(ok[i][j]) ans++;
        }
    }

    cout << ans << endl;
}