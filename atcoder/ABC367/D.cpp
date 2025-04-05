#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Pedometer 
//    https://atcoder.jp/contests/abc367/tasks/abc367_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    int N2 = N * 2;
    vector<long long> S(N2+1);
    for(int i = 0; i < N2; i++) {
        S[i+1] = (S[i] + A[i % N]) % M;
    }
    
    map<int, long long> cnt;
    for(int i = 0; i < N; i++) {
        cnt[S[i]]++;
    }

    long long ans = 0;
    for(int i = N; i < N2; i++) {
        cnt[S[i-N]]--;
        ans += cnt[S[i]];
        cnt[S[i]]++;
    } 

    cout << ans << endl;
}