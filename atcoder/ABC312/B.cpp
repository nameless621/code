#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - TaK Code
//    https://atcoder.jp/contests/abc312/tasks/abc312_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    auto check = [&](int x, int y) {
        for(int i = x; i < x + 3; i++) {
            for(int j = y; j < y + 3; j++) {
                if(S[i][j] != '#') return false;
            }
        }

        for(int k = x; k < x + 3; k++) {
            if(S[k][y + 3] != '.') return false;
        }

        for(int k = y; k < y + 4; k++) {
            if(S[x + 3][k] != '.') return false;
        }

        for(int i = x + 6; i < x + 9; i++) {
            for(int j = y + 6; j < y + 9; j++) {
                if(S[i][j] != '#') return false;
            }
        }

        for(int k = x + 6; k < x + 9; k++) {
            if(S[k][y + 5] != '.') return false;
        }

        for(int k = y + 5; k < y + 9; k++) {
            if(S[x + 5][k] != '.') return false;
        }

        return true;
    };

    for(int i = 0; i <= N - 9; i++) {
        for(int j = 0; j <= M - 9; j++) {
            if(check(i, j)) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}