#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Adjacency List
//    https://atcoder.jp/contests/abc276/tasks/abc276_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    for(int i = 0; i < N; i++) {
        sort(G[i].begin(), G[i].end());
        cout << G[i].size() << " ";
        for(int j : G[i]) cout << j + 1 << " ";
        cout << endl;
    }
}