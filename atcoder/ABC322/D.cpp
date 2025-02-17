#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Polyomino
//    https://atcoder.jp/contests/abc322/tasks/abc322_d



vector<string> rot(vector<string>& S) {
    vector<string> res(4, string(4, '.'));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            res[i][j] = S[4-j-1][i];
        }
    }
    return res;
}

vector<string> normalize(vector<string>& S) {
    vector<string> res(4, string(4, '.'));
    int x = 1e9, y = 1e9;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(S[i][j] == '#') {
                x = min(x, i);
                y = min(y, j);
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(S[i][j] == '#') {
                res[i-x][j-y] = S[i][j];
            }
        }
    }
    return res;
}

bool move_right(vector<string>& S) {
    for(int i = 0; i < 4; i++) {
        if(S[i][3] == '#') return false;
        rotate(S[i].rbegin(), S[i].rbegin()+1, S[i].rend());
    }
    return true;
}

bool move_under(vector<string>& S) {
    for(int j = 0; j < 4; j++) {
        if(S[3][j] == '#') return false;
    }
    for(int i = 3; i >= 1; i--) {
        swap(S[i], S[i-1]);
    }
    return true;
}

bool check(vector<vector<vector<string>>>& mino, int x, int y, int z) {
    bool res = true;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int cnt = 0;
            if(mino[0][x][i][j] == '#') cnt++;
            if(mino[1][y][i][j] == '#') cnt++;
            if(mino[2][z][i][j] == '#') cnt++;
            if(cnt != 1) res = false;
        }
    }
    return res;
}

int main() {
    vector<vector<string>> P(3, vector<string>(4));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> P[i][j];
        }
    }

    vector<vector<vector<string>>> mino(3);
    for(int i = 0; i < 3; i++) {
        for(int k = 0; k < 4; k++) {
            P[i] = rot(P[i]);
            vector<string> S = normalize(P[i]);
            do {
                vector<string> T = S;
                do {
                    mino[i].push_back(T);
                } while(move_right(T));
            } while(move_under(S));
        }
    }

    bool ok = false;
    for(int i = 0; i < (int)mino[0].size(); i++) {
        for(int j = 0; j < (int)mino[1].size(); j++) {
            for(int k = 0; k < (int)mino[2].size(); k++) {
                if(check(mino, i, j, k)) {
                    ok = true;
                }
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}