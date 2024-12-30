#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Connect 6 
//    https://atcoder.jp/contests/abc241/tasks/abc241_c



const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    auto check = [&](int i, int j) {
        bool res = false;
        for(int k = 0; k < 8; k++) {
            int cnt = (S[i][j] == '#' ? 1 : 0);
            int white = (S[i][j] == '.' ? 1 : 0);
            int x = i + dx[k], y = j + dy[k];
            while(0 <= x && x < N && 0 <= y && y < N && cnt < 6) {
                cnt++;
                if(S[x][y] == '.') white++;
                x += dx[k];
                y += dy[k];
            }
            if(white <= 2 && cnt == 6) res = true;
        }
        return res;
    };

    bool ok = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(ok) continue;
            if(check(i, j)) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}