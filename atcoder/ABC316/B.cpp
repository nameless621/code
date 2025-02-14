#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - MissingNo.
//    https://atcoder.jp/contests/abc317/tasks/abc317_b



int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for(int i = 0; i < N-1; i++) {
        if(A[i+1] - A[i] > 1) {
            cout << A[i] + 1 << endl;
            return 0;
        }
    }
}