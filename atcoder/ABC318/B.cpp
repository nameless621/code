#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Overlapping sheets
//    https://atcoder.jp/contests/abc318/tasks/abc318_b



int main() {
    int N;
    cin >> N;

    vector<vector<bool>> ok(101, vector<bool>(101));
    for(int k = 0; k < N; k++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        for(int i = A; i < B; i++) {
            for(int j = C; j < D; j++) {
                ok[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            if(ok[i][j]) ans++;
        }
    }

    cout << ans << endl;
}