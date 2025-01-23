#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Line Sensor
//    https://atcoder.jp/contests/abc274/tasks/abc274_b



int main() {
    int H, W;
    cin >> H >> W;
    
    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    for(int j = 0; j < W; j++) {
        int res = 0;
        for(int i = 0; i < H; i++) {
            if(C[i][j] == '#') res++;
        }
        cout << res << " ";
    }
    
    cout << endl;
}