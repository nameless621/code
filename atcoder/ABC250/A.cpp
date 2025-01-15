#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Adjacent Squares 
//    https://atcoder.jp/contests/abc250/tasks/abc250_a



int main() {
    int H, W, R, C;
    cin >> H >> W >> R >> C;
    R--; C--;

    int ans = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for(int i = 0; i < 4; i++) {
        int x = R + dx[i];
        int y = C + dy[i];
        if(x < 0 || x >= H || y < 0 || y >= W) continue;
        ans++;
    }

    cout << ans << endl;
}