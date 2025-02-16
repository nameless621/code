#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Cutoff
//    https://atcoder.jp/contests/abc321/tasks/abc321_b



int main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    for(int i = 0; i < N-1; i++) cin >> A[i];

    int ans = 10101;
    for(int p = 0; p <= 100; p++) {
        A[N-1] = p;
        auto B = A;
        sort(B.begin(), B.end());
        int sum = 0;
        for(int i = 1; i < N - 1; i++) {
            sum += B[i];
        }
        if(X <= sum) ans = min(ans, p);
    }

    if(ans == 10101) ans = -1;
    cout << ans << endl;
}