#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Rotate Colored Subsequence
//    https://atcoder.jp/contests/abc314/tasks/abc314_c



int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
    }

    vector<vector<int>> idx(M);
    vector<string> t(M);
    for(int i = 0; i < N; i++) {
        t[C[i]] += S[i];
        idx[C[i]].push_back(i);
    }

    for(int i = 0; i < M; i++) {
        rotate(t[i].rbegin(), t[i].rbegin()+1, t[i].rend());
        for(int j = 0; j < (int)t[i].size(); j++) {
            S[idx[i][j]] = t[i][j];
        }
    }

    cout << S << endl;
}