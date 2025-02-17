#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Festival
//    https://atcoder.jp/contests/abc322/tasks/abc322_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> D(N, N+1);
    for(int i = 0; i < M; i++) {
        int A;
        cin >> A, A--;
        D[A] = 0;
    }

    for(int i = N-2; i >= 0; i--) {
        D[i] = min(D[i], D[i+1] + 1);
    }

    for(int i = 0; i < N; i++) {
        cout << D[i] << endl;
    }
}