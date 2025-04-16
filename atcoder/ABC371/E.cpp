#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - I Hate Sigma Problems
//    https://atcoder.jp/contests/abc371/tasks/abc371_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    vector<int> pre(N+1, -1);
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        long long x = i - pre[A[i]];
        ans += x * (N - i);
        pre[A[i]] = i;
    }

    cout << ans << endl;
}