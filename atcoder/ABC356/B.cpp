#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Nutrients 
//    https://atcoder.jp/contests/abc356/tasks/abc356_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    for(int& a : A) cin >> a;

    vector<int> sum(M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int X;
            cin >> X;
            sum[j] += X;
        }
    }

    bool ok = true;
    for(int i = 0; i < M; i++) {
        if(sum[i] < A[i]) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}