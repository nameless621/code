#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Dash
//    https://atcoder.jp/contests/abc303/tasks/abc303_c



int main() {
    int N, M, H, K;
    string S;
    cin >> N >> M >> H >> K >> S;

    set<pair<int, int>> E;
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        E.emplace(x, y);
    }

    bool ok = true;
    int x = 0, y = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') x++;
        if(S[i] == 'L') x--;
        if(S[i] == 'U') y++;
        if(S[i] == 'D') y--;
        H--;
        if(H < 0) {
            ok = false;
            break;
        }
        if(E.count({x, y}) && H < K) {
            H = K;
            E.erase({x, y});
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}