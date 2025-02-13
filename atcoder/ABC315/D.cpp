#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Magical Cookies
//    https://atcoder.jp/contests/abc315/tasks/abc315_d



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> c(H);
    vector<vector<int>> x(H, vector<int>(26));
    vector<vector<int>> y(W, vector<int>(26));
    for(int i = 0; i < H; i++) {
        cin >> c[i];
        for(int j = 0; j < W; j++) {
            x[i][c[i][j] - 'a']++;
            y[j][c[i][j] - 'a']++;
        }
    }

    bool upd = true;
    int hc = H, wc = W;
    while(upd) {
        upd = false;
        vector<pair<int, int>> erase_x, erase_y;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < 26; j++) {
                if(x[i][j] == wc && wc >= 2) {
                    erase_x.emplace_back(i, j);
                }
            }
        }
        for(int i = 0; i < W; i++) {
            for(int j = 0; j < 26; j++) {
                if(y[i][j] == hc && hc >= 2) {
                    erase_y.emplace_back(i, j);
                }
            }
        }

        for(auto[idx, t] : erase_x) {
            x[idx][t] = 0;
            for(int j = 0; j < W; j++) {
                if(c[idx][j] - 'a' == t) {
                    y[j][t]--;
                }
            }
            hc--;
        }
        for(auto[idx, t] : erase_y) {
            y[idx][t] = 0;
            for(int i = 0; i < H; i++) {
                if(c[i][idx] - 'a' == t) {
                    x[i][t]--;
                }
            }
            wc--;
        }
        if(erase_x.size() || erase_y.size()) upd = true;
    }

    cout << hc * wc << endl;
}