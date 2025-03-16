#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Divisible 
//    https://atcoder.jp/contests/abc347/tasks/abc347_a



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++) {
        if(A[i] % K == 0) {
            cout << A[i] / K << " ";
        }
    }

    cout << endl;
}