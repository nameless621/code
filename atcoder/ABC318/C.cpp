#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Blue Spring
//    https://atcoder.jp/contests/abc318/tasks/abc318_c



int main() {
    int N, D, P;
    cin >> N >> D >> P;
    
    vector<int> F(N);
    for(int i = 0; i < N; i++) cin >> F[i];

    sort(F.rbegin(), F.rend());
    vector<long long> S(N+1);
    for(int i = 0; i < N; i++) {
        S[i+1] = S[i] + F[i];
    }

    long long ans = accumulate(F.begin(), F.end(), 0ll);
    for(int k = 1; ; k++) {
        int i = D * k;
        long long sum = (long long)P * k;
        ans = min(ans, (S[N] - S[min(N, i)]) + sum);
        if(i >= N) break;
    }

    cout << ans << endl;
}