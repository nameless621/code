#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Gomamayo Sequence
//    https://atcoder.jp/contests/abc346/tasks/abc346_d



int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];

    vector<long long> L(N+1), R(N+1);
    for(int i = 0; i < N; i++) {
        if(i & 1 && S[i] == '0') L[i+1] += C[i];
        if(~i & 1 && S[i] == '1') L[i+1] += C[i];
        if(i & 1 && S[i] == '1') R[i+1] += C[i];
        if(~i & 1 && S[i] == '0') R[i+1] += C[i];
        L[i+1] += L[i];
        R[i+1] += R[i];
    }

    long long ans = 1e18;
    for(int i = 1; i < N; i++) {
        long long x = L[i] + (R[N] - R[i]);
        long long y = R[i] + (L[N] - L[i]);
        ans = min(ans, min(x, y));
    }

    cout << ans << endl;
}