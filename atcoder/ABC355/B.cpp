#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Piano 2
//    https://atcoder.jp/contests/abc355/tasks/abc355_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int& a : A) cin >> a;
    for(int& b : B) cin >> b;

    vector<pair<int, int>> C;
    for(int i = 0; i < N; i++) {
        C.emplace_back(A[i], 0);
    }
    for(int i = 0; i < M; i++) {
        C.emplace_back(B[i], 1);
    }

    sort(C.begin(), C.end());
    bool res = false;
    for(int i = 0; i < N+M-1; i++) {
        if(C[i].second == 0 && C[i].second == C[i+1].second) {
            res = true;
        }
    }

    cout << (res ? "Yes" : "No") << endl;
}