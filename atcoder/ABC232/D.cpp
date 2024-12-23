#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Weak Takahashi
//    https://atcoder.jp/contests/abc232/tasks/abc232_d



int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++) {
        cin >> C[i];
    }

    int INF = INT_MIN;
    vector<vector<int>> DP(H, vector<int>(W, INF));
    DP[0][0] = 1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(DP[i][j] == INF) continue;
            if(i + 1 < H && C[i+1][j] == '.') DP[i+1][j] = max(DP[i+1][j], DP[i][j] + 1);
            if(j + 1 < W && C[i][j+1] == '.') DP[i][j+1] = max(DP[i][j+1], DP[i][j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans = max(ans, DP[i][j]);
        }
    }

    cout << ans << endl;
}