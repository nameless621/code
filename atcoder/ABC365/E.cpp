#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Xor Sigma Problem
//    https://atcoder.jp/contests/abc365/tasks/abc365_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    vector<int> S(N+1);
    for(int i = 0; i < N; i++) {
        S[i+1] = S[i] ^ A[i];
    }

    long long ans = 0;
    for(int k = 0; k < 30; k++) {
        long long cnt0 = 0, cnt1 = 0;
        for(int i = 0; i <= N; i++) {
            if(S[i] >> k & 1) cnt1++;
            else cnt0++;
        }
        ans += (1ll << k) * cnt0 * cnt1;
    }

    ans -= accumulate(A.begin(), A.end(), 0ll);
    cout << ans << endl;
}