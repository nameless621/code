#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Double Sum
//    https://atcoder.jp/contests/abc351/tasks/abc351_f



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int& a : A) cin >> a;

    vector<int> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    int M = B.size();
    fenwick_tree<long long> val(M), cnt(M);
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        long long x = val.sum(0, idx);
        long long y = cnt.sum(0, idx);
        ans += A[i] * y - x;
        val.add(idx, A[i]);
        cnt.add(idx, 1);
    }

    cout << ans << endl;
}