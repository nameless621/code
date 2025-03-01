#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Reindeer and Sleigh
//    https://atcoder.jp/contests/abc334/tasks/abc334_d



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> R(N);
    for(int i = 0; i < N; i++) cin >> R[i];

    sort(R.begin(), R.end());
    vector<long long> S(N+1);
    for(int i = 0; i < N; i++) {
        S[i+1] = S[i] + R[i];
    }

    while(Q--) {
        long long X;
        cin >> X;
        int res = upper_bound(S.begin(), S.end(), X) - S.begin();
        cout << res - 1 << '\n';
    }
}