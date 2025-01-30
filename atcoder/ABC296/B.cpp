#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Chessboard
//    https://atcoder.jp/contests/abc296/tasks/abc296_b



int main() {
    vector<string> S(8);
    for(int i = 0; i < 8; i++) cin >> S[i];

    reverse(S.begin(), S.end());
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(S[i][j] == '.') continue;
            char c = 'a' + j;
            cout << c << i+1 << endl;
            return 0;
        }
    }
}