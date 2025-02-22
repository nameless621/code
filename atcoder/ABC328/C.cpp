#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Consecutive
//    https://atcoder.jp/contests/abc328/tasks/abc328_c



int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    vector<long long> res(N+1);
    for(int i = 0; i < N; i++) {
        if(i+1 < N && S[i] == S[i+1]) res[i+1] = res[i] + 1;
        else res[i+1] = res[i];
    }

    while(Q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << res[r] - res[l] << '\n';
    }
}