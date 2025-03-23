#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Bingo 2
//    https://atcoder.jp/contests/abc355/tasks/abc355_c



int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> id(N*N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int idx = i * N + j;
            id[idx] = {i, j};
        }
    }

    set<pair<int, int>> naname2;
    int j = N-1;
    for(int i = 0; i < N; i++) {
        naname2.emplace(i, j);
        j--;
    }

    vector<int> tate(N), yoko(N);
    int naname1 = 0;
    for(int k = 0; k < T; k++) {
        int A;
        cin >> A;
        A--;
        auto[i, j] = id[A];
        yoko[i]++;
        tate[j]++;
        if(i == j) naname1++;
        naname2.erase(id[A]);
        if(yoko[i] == N || tate[j] == N || naname1 == N || !naname2.size()) {
            cout << k+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}