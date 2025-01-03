#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Shapes
//    https://atcoder.jp/contests/abc218/tasks/abc218_c



vector<string> rot(vector<string> &S, int N) {
    vector<string> res(N, string(N, '.'));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res[i][j] = S[N-j-1][i];
        }
    } 
    return res;
}

vector<string> func(vector<string> &S, int N) {
    vector<string> res(N, string(N, '.'));
    int x = 1e9, y = 1e9;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == '#') {
                x = min(x, i);
                y = min(y, j);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == '#') {
                res[i - x][j - y] = S[i][j];
            }
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < N; i++) cin >> T[i];

    bool ok = false;
    T = func(T, N);
    for(int i = 0; i < 4; i++) {
        if(func(S, N) == T) ok = true;
        S = rot(S, N);
    }

    cout << (ok ? "Yes" : "No") << endl;
}