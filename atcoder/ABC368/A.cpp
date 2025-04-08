#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Cut 
//    https://atcoder.jp/contests/abc368/tasks/abc368_a



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    vector<int> B;
    for(int i = N-K; i < N; i++) {
        B.push_back(A[i]);
    }
    for(int i = 0; i < N-K; i++) {
        B.push_back(A[i]);
    }

    for(int i = 0; i < N; i++) {
        cout << B[i] << (i < N-1 ? " " : "\n");
    }
}