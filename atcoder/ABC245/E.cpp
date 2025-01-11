#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Wrapping Chocolate
//    https://atcoder.jp/contests/abc245/tasks/abc245_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N), C(M), D(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < M; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> D[i];

    vector<tuple<int, int, int>> P;
    for(int i = 0; i < N; i++) P.emplace_back(A[i], B[i], 0);
    for(int i = 0; i < M; i++) P.emplace_back(C[i], D[i], 1);
    sort(P.rbegin(), P.rend());

    multiset<int> S;
    for(int i = 0; i < N + M; i++) {
        auto[x, y, t] = P[i];
        if(t == 1) {
            S.insert(y);
        }
        else {
            auto itr = S.lower_bound(y);
            if(itr == S.end()) {
                cout << "No" << endl;
                return 0;
            }
            S.erase(itr);
        }
    }

    cout << "Yes" << endl;
}