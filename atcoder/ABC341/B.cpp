#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Foreign Exchange
//    https://atcoder.jp/contests/abc341/tasks/abc341_b



int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N-1; i++) {
        int S, T;
        cin >> S >> T;
        A[i+1] += A[i] / S * T;
    }

    cout << A[N-1] << endl;
}