#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Dance
//    https://atcoder.jp/contests/abc236/tasks/abc236_d



int main() {
    int N;
    cin >> N;
    N *= 2;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    auto dfs = [&](auto dfs, int sum, int st, int now) -> void {
        if(now == (1 << N) - 1) {
            ans = max(ans, sum);
            return;
        }

        for(int i = st; i < N; i++) {
            if(now >> i & 1) continue;
            for(int j = i + 1; j < N; j++) {
                if(now >> j & 1) continue;
                int nex = now | (1 << i) | (1 << j);
                dfs(dfs, sum ^ A[i][j], i + 1, nex);
            }
        }
    };

    dfs(dfs, 0, 0, 0);
    cout << ans << endl;
}