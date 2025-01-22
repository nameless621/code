#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Belt Conveyor
//    https://atcoder.jp/contests/abc265/tasks/abc265_c



int main() {
    int H, W;
    cin >> H >> W;
    
    vector<string> G(H);
    for(int i = 0; i < H; i++) cin >> G[i];

    int x = 0, y = 0;
    vector ok(H, vector<bool>(W));
    while(!ok[x][y]) {
        int i = x, j = y;
        ok[i][j] = true;
        if(G[x][y] == 'U') i--;
        if(G[x][y] == 'D') i++;
        if(G[x][y] == 'L') j--;
        if(G[x][y] == 'R') j++;
        if(i < 0 || i >= H || j < 0 || j >= W) continue;
        if(ok[i][j]) {
            cout << -1 << endl;
            return 0;
        }
        x = i;
        y = j;
    }

    cout << x + 1 << " " << y + 1 << endl;
}