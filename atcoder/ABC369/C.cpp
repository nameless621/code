#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Count Arithmetic Subarrays
//    https://atcoder.jp/contests/abc369/tasks/abc369_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    long long ans = N;
    int r = 0;
    for(int l = 0; l < N-1; l++) {
        r = max(l, r);
        while(r+1 < N && (A[l+1] - A[l]) == (A[r+1] - A[r])) r++;
        long long d = r - l;
        ans += d * (d+1) / 2;
        l = r-1;
    }

    cout << ans << endl;
}