#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Adjacent Product
//    https://atcoder.jp/contests/abc346/tasks/abc346_a



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N-1; i++) {
        cout << A[i] * A[i+1] << (i < N-2 ? " " : "\n");
    }
}