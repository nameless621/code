#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Make Them Narrow
//    https://atcoder.jp/contests/abc361/tasks/abc361_c



int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int& a : A) cin >> a;
    sort(A.begin(), A.end());

    int ans = 2e9;
    for(int i = N-K-1; i < N; i++) {
        ans = min(ans, A[i] - A[i-(N-K-1)]);
    }

    cout << ans << endl;
}