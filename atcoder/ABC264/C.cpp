#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Matrix Reducing
//    https://atcoder.jp/contests/abc264/tasks/abc264_c



vector<vector<int>> read() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> S(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }
    return S;
}

int main() {
    auto A = read();
    auto B = read();

    bool ok = false;
    int H = A.size(), W = A[0].size();
    for(int bit1 = 0; bit1 < (1 << H); bit1++) {
        for(int bit2 = 0; bit2 < (1 << W); bit2++) {
            vector<vector<int>> res;
            for(int i = 0; i < H; i++) {
                if(~bit1 >> i & 1) continue;
                vector<int> temp;
                for(int j = 0; j < W; j++) {
                    if(~bit2 >> j & 1) continue;
                    temp.push_back(A[i][j]);
                }
                res.push_back(temp);
            }
            if(res == B) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}