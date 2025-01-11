#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Polynomial division
//    https://atcoder.jp/contests/abc245/tasks/abc245_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1), B(M + 1), C(N + M + 1);
    for(int i = 0; i < N + 1; i++) cin >> A[i];
    for(int i = 0; i < N + M + 1; i++) cin >> C[i];

    for(int i = M; i >= 0; i--) {
        B[i] = C[i + N] / A[N];
        for(int j = 0; j < N + 1; j++) {
            C[i + j] -= A[j] * B[i];
        }
    }

    for(int i = 0; i < M + 1; i++) {
        cout << B[i] << " ";
        if(i == M) cout << endl;
    }
}