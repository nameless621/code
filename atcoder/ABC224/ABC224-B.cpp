#include <bits/stdc++.h>
using namespace std;


//    B - Mongeness
//    https://atcoder.jp/contests/abc224/tasks/abc224_b



int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    bool ok = true;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int k = i + 1; k < H; k++) {
                for(int l = j + 1; l < W; l++) {
                    if(A[i][j] + A[k][l] > A[k][j] + A[i][l]) {
                        ok = false;
                    }
                }
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}