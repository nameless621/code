#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Max/Min
//    https://atcoder.jp/contests/abc356/tasks/abc356_e



int main() {
    int N;
    cin >> N;

    int M = 1e6 + 9;
    vector<long long> A(N), cnt(M);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    vector<long long> S(M);
    for(int i = 1; i < M; i++) {
        for(int j = i; j < M; j += i) {
            S[j] += cnt[i];
        }
    }

    for(int i = 1; i < M-1; i++) {
        S[i+1] += S[i];
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans += S[A[i]] - cnt[A[i]];
    }

    for(int i = 0; i < M; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans << endl;
}