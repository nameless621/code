#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Standings
//    https://atcoder.jp/contests/abc308/tasks/abc308_c



int main() {
    int N;
    cin >> N;

    vector<tuple<long long, long long, int>> T;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        T.emplace_back(A, B, i);
    }

    sort(T.begin(), T.end(), [&](auto& X, auto& Y) {
        auto[Ai, Bi, i] = X;
        auto[Aj, Bj, j] = Y;
        long long res_i = Ai * (Aj + Bj);
        long long res_j = Aj * (Ai + Bi);
        if(res_i != res_j) return res_i > res_j;
        else return i < j;
    });

    for(int i = 0; i < N; i++) {
        auto[A, B, idx] = T[i];
        cout << idx + 1 << " ";
        if(i == N - 1) cout << endl;
    }
}