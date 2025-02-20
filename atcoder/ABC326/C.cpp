#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Peak
//    https://atcoder.jp/contests/abc326/tasks/abc326_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int ans = 0, r = 0;
    for(int l = 0; l < N; l++) {
        r = max(r, l);
        while(r+1 < N && abs(A[l] - A[r+1]) < M) r++;
        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;
}