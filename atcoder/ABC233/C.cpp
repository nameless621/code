#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Product
//    https://atcoder.jp/contests/abc233/tasks/abc233_c



int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<vector<long long>> A(N);
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;
        A[i].resize(L);
        for(int j = 0; j < L; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    auto dfs = [&](auto dfs, int idx, long long sum) -> void {
        if(idx == N) {
            if(sum == X) ans++;
            return;
        }

        for(int j = 0; j < (int)A[idx].size(); j++) {
            if((double)sum <= (double)X / A[idx][j]) {
                dfs(dfs, idx + 1, sum * A[idx][j]);
            }
        }
    };

    dfs(dfs, 0, 1);
    cout << ans << endl;
}