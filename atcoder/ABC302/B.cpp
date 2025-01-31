#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};


//    B - Find snuke
//    https://atcoder.jp/contests/abc302/tasks/abc302_b



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    bool flag = false;
    string t = "snuke";
    vector<pair<int, int>> P;
    auto f = [&](int x, int y) {
        for(int k = 0; k < 8; k++) {
            int i = x, j = y;
            for(int l = 0; l < 5; l++) {
                if(S[i][j] == t[l]) P.emplace_back(i, j);
                i += dx[k];
                j += dy[k];
                if(i < 0 || i >= H || j < 0 || j >= W) break;
            }
            if((int)P.size() == 5) {
                flag = true;
                return;
            } 
            else P.clear();
        }
    };

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == 's' && !flag) {
                f(i, j);
            }
        }
    }

    for(auto[x, y] : P) {
        cout << x + 1 << " " << y + 1 << endl;
    }
}