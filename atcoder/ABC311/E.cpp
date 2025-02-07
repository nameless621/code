#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Defect-free Squares
//    https://atcoder.jp/contests/abc311/tasks/abc311_e



int main() {
    int H, W, N;
    cin >> H >> W >> N;
    
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        grid[a-1][b-1] = false;
    }

    long long ans = 0;
    vector<vector<long long>> dp(H, vector<long long>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(!grid[i][j]) continue;
            if(i == 0 || j == 0) dp[i][j] = 1;
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            ans += dp[i][j];
        }
    }

    cout << ans << endl;
}