#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Subsegment Reverse
//    https://atcoder.jp/contests/abc356/tasks/abc356_a



int main() {
    int N, L, R;
    cin >> N >> L >> R;
    L--;

    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    reverse(A.begin()+L, A.begin()+R);

    for(int i = 0; i < N; i++) {
        cout << A[i] << (i < N-1 ? " " : "\n");
    }
}