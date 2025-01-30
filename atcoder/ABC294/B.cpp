#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - ASCII Art
//    https://atcoder.jp/contests/abc294/tasks/abc294_b



int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        string S;
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 0) S += '.';
            else {
                char c = 'A' + (A[i][j] - 1);
                S += c;
            }
        }
        cout << S << endl;
    }
}