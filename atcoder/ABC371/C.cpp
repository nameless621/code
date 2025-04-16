#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Make Isomorphic
//    https://atcoder.jp/contests/abc371/tasks/abc371_c



vector<vector<bool>> read(int N) {
    int M;
    cin >> M;
    vector<vector<bool>> res(N, vector<bool>(N));
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        res[u][v] = res[v][u] = true;
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    auto G = read(N);
    auto H = read(N);

    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> P(N);
    iota(P.begin(), P.end(), 0);

    int ans = INT_MAX;
    do {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            for(int j = i+1; j < N; j++) {
                if(H[i][j] != G[P[i]][P[j]]) {
                    sum += A[i][j];
                }
            }
        }
        ans = min(ans, sum);
    } while(next_permutation(P.begin(), P.end()));

    cout << ans << endl;
}