#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Tile Pattern
//    https://atcoder.jp/contests/abc331/tasks/abc331_d



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<string> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    vector<vector<int>> grid(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = (P[i][j] == 'B');
        }
    }

    vector<vector<long long>> sum(N+1, vector<long long>(N+1));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sum[i+1][j+1] = grid[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
        }
    }

    long long total = sum[N][N];

    auto f = [&](int i, int j) -> long long {
        if(i < 0 || j < 0) return 0;
        i++; j++;
        long long x = i / N, xx = i % N;
        long long y = j / N, yy = j % N;
        long long res = x * y * total;
        res += x * sum[N][yy];
        res += y * sum[xx][N];
        res += sum[xx][yy];
        return res;
    };

    while(Q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        long long ans = f(C, D) - f(A-1, D) - f(C, B-1) + f(A-1, B-1);
        cout << ans << '\n';
    }
}