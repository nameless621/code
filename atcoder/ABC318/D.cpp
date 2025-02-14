#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - General Weighted Max Matching
//    https://atcoder.jp/contests/abc318/tasks/abc318_d



int main() {
    int N;
    cin >> N;

    vector<vector<int>> D(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            cin >> D[i][j];
        }
    }

    int N2 = 1 << N;
    long long INF = -1e18;
    vector<long long> dp(N2, INF);
    dp[0] = 0;
    for(int i = 0; i < N2; i++) {
        if(dp[i] == INF) continue;
        for(int j = 0; j < N; j++) {
            if(i >> j & 1) continue;
            for(int k = j+1; k < N; k++) {
                if(i >> k & 1) continue;
                int nex = i | (1 << j) | (1 << k);
                dp[nex] = max(dp[nex], dp[i] + D[j][k]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}