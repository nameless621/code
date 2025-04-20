#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - XOR on Grid Path
//    https://atcoder.jp/contests/abc271/tasks/abc271_f



int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    map<pair<int, int>, map<int, int>> pre, suf;
    auto f1 = [&](auto f1, int i, int j, int cnt, int now) -> void {
        now ^= A[i][j];
        if(cnt == N) {
            pre[{i, j}][now]++;
            return;
        }
        f1(f1, i+1, j, cnt+1, now);
        f1(f1, i, j+1, cnt+1, now);
    };

    auto f2 = [&](auto f2, int i, int j, int cnt, int now) -> void {
        now ^= A[i][j];
        if(cnt == N-1) {
            suf[{i, j}][now]++;
            return;
        }
        f2(f2, i-1, j, cnt+1, now);
        f2(f2, i, j-1, cnt+1, now);
    };

    f1(f1, 0, 0, 1, 0);
    f2(f2, N-1, N-1, 1, 0);

    long long ans = 0;
    for(auto[pos, mp] : pre) {
        auto[i, j] = pos;
        for(auto[k, v] : mp) {
            ans += (long long)v * suf[{i+1, j}][k];
            ans += (long long)v * suf[{i, j+1}][k];
        }
    }

    cout << ans << endl;
}