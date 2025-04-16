#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - 1D Country
//    https://atcoder.jp/contests/abc371/tasks/abc371_d



int main() {
    int N;
    cin >> N;

    vector<int> X(N), P(N);
    for(int& x : X) cin >> x;
    for(int& p : P) cin >> p;

    vector<long long> S(N+1);
    for(int i = 0; i < N; i++) {
        S[i+1] = S[i] + P[i];
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R;
        cin >> L >> R;

        int i = lower_bound(X.begin(), X.end(), L) - X.begin();
        int j = upper_bound(X.begin(), X.end(), R) - X.begin();
        cout << S[j] - S[i] << '\n';
    }
}