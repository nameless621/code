#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Perfect Bus
//    https://atcoder.jp/contests/abc339/tasks/abc339_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans += A[i];
        if(ans < 0) ans = 0;
    }

    cout << ans << endl;
}