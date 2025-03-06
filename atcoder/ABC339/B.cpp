#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Langton's Takahashi
//    https://atcoder.jp/contests/abc339/tasks/abc339_b



int main() {
    int H, W, N;
    cin >> H >> W >> N;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<string> grid(H, string(W, '.'));

    int i = 0, j = 0, k = 0;
    while(N--) {
        if(grid[i][j] == '.') {
            grid[i][j] = '#';
            k = (k + 1) % 4;
        }
        else {
            grid[i][j] = '.';
            k = (k - 1 + 4) % 4;
        }
        i += dx[k];
        j += dy[k];
        if(i < 0) i = H-1;
        if(i >= H) i = 0;
        if(j < 0) j = W-1;
        if(j >= W) j = 0;
    }

    for(int i = 0; i < H; i++) {
        cout << grid[i] << endl;
    }
}