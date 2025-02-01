#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Discord
//    https://atcoder.jp/contests/abc303/tasks/abc303_b



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> a(M, vector<int>(N));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    set<pair<int, int>> s;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N - 1; j++) {
            int x = a[i][j], y = a[i][j+1];
            if(x > y) swap(x, y);
            s.emplace(x, y);
        }
    }

    N--;
    int ans = N * (N + 1) / 2 - (int)s.size();
    cout << ans << endl;
}