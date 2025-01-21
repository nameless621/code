#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - 1D Pawn 
//    https://atcoder.jp/contests/abc257/tasks/abc257_b



int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
    }

    while(Q--) {
        int L;
        cin >> L;
        L--;
        if(A[L] == N) continue;
        if(L + 1 < K && A[L] + 1 == A[L+1]) continue;
        A[L]++;
    }

    for(int i = 0; i < K; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
