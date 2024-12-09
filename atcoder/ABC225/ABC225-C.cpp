#include <bits/stdc++.h>
using namespace std;


//    C - Calendar Validator
//    https://atcoder.jp/contests/abc225/tasks/abc225_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> B(N, vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> B[i][j];
            B[i][j]--;
        }
    }

    int X = B[0][0] / 7;
    int Y = B[0][0] % 7;

    bool ok = true;
    if(Y + M - 1 >= 7) ok = false;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int Z = (X + i) * 7 + (Y + j);
            if(B[i][j] != Z) ok = false;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}