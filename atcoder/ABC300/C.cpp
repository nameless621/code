#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Cross
//    https://atcoder.jp/contests/abc300/tasks/abc300_c



const int dx[] = {-1, -1, 1, 1};
const int dy[] = {-1, 1, -1, 1};

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    auto check = [&](int x, int y) {
        int res = 0;
        bool upd = true;
        while(upd) {
            for(int k = 0; k < 4; k++) {
                int i = x + dx[k] * (res + 1);
                int j = y + dy[k] * (res + 1);
                if(i < 0 || i >= H || j < 0 || j >= W) {
                    upd = false;
                    break;
                }
                if(C[i][j] == '.') {
                    upd = false;
                    break;
                }
            }
            if(upd) res++;
        }
        return res;
    };

    vector<int> ans(min(H, W) + 1);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(C[i][j] == '#') {
                ans[check(i, j)]++;
            }
        }
    }

    for(int i = 1; i <= min(H, W); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}