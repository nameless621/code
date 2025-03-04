#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Cheating Gomoku Narabe
//    https://atcoder.jp/contests/abc337/tasks/abc337_d



int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int ans = 1e9;
    for(int i = 0; i < H; i++) {
        int l = 0, cnt = 0, len = 0;
        for(int r = 0; r < W; r++) {
            if(S[i][r] == 'x') {
                l = r+1;
                cnt = len = 0;
                continue;
            }
            if(S[i][r] == '.') cnt++;
            len++;
            if(len == K) {
                ans = min(ans, cnt);
                if(S[i][l] == '.') cnt--;
                len--;
                l++;
            }
        }
    }

    for(int j = 0; j < W; j++) {
        int l = 0, cnt = 0, len = 0;
        for(int r = 0; r < H; r++) {
            if(S[r][j] == 'x') {
                l = r+1;
                cnt = len = 0;
                continue;
            }
            if(S[r][j] == '.') cnt++;
            len++;
            if(len == K) {
                ans = min(ans, cnt);
                if(S[l][j] == '.') cnt--;
                len--;
                l++;
            }
        }
    }

    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}