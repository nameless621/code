#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Sleep Log
//    https://atcoder.jp/contests/abc305/tasks/abc305_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<long long> S(N+1);
    for(int i = 2; i < N; i++) {
        if(~i & 1) S[i+1] += A[i] - A[i-1];
        S[i+1] += S[i];
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        int x = lower_bound(A.begin(), A.end(), l) - A.begin();
        int y = lower_bound(A.begin(), A.end(), r) - A.begin();
        long long res = S[y] - S[x+1];
        if(~x & 1) res += A[x] - l;
        if(~y & 1) res += r - A[y-1];
        cout << res << endl;
    }
}