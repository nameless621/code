#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Strictly Superior
//    https://atcoder.jp/contests/abc310/tasks/abc310_b



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> P(N), C(N);
    vector<vector<int>> F(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
        F[i].resize(C[i]);
        for(int j = 0; j < C[i]; j++) {
            cin >> F[i][j];
        }
    }

    bool ok = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(P[i] < P[j]) continue;
            bool flag = false;
            for(int k = 0; k < C[i]; k++) {
                if(find(F[j].begin(), F[j].end(), F[i][k]) == F[j].end()) {
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            if(P[i] > P[j] || (int)F[i].size() < (int)F[j].size()) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}