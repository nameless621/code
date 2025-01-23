#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Counting Squares
//    https://atcoder.jp/contests/abc275/tasks/abc275_c



int main() {
    vector<string> S(9);
    for(int i = 0; i < 9; i++) cin >> S[i];

    vector<pair<int, int>> P;
    set<pair<int, int>> st;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(S[i][j] == '#') {
                P.push_back({i, j});
                st.insert({i, j});
            }
        }
    }

    int ans = 0, N = P.size();
    for(int i = 0; i < N; i++) {
        auto[x1, y1] = P[i];
        for(int j = i + 1; j < N; j++) {
            auto[x2, y2] = P[j];
            pair<int, int> a = {x2 - y2 + y1, y2 + x2 - x1};
            pair<int, int> b = {x1 - y2 + y1, y1 + x2 - x1};
            if(st.count(a) && st.count(b)) ans++;
        }
    }

    cout << ans / 2 << endl;
}