#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Sigma Problem 
//    https://atcoder.jp/contests/abc353/tasks/abc353_c



int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for(auto& a : A) cin >> a;

    sort(A.begin(), A.end());
    long long cnt = 0, mod = 1e8;
    for(int i = 0; i < N; i++) {
        int j = lower_bound(A.begin()+i+1, A.end(), mod - A[i]) - A.begin();
        cnt += N - j;
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans += A[i] * (N-1);
    }

    ans -= mod * cnt;
    cout << ans << endl;
}