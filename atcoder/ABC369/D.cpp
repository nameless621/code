#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Bonus EXP
//    https://atcoder.jp/contests/abc369/tasks/abc369_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    long long INF = -1e18;
    vector<long long> dp = {0, A[0]};
    for(int i = 1; i < N; i++) {
        vector<long long> p(2, INF);
        swap(dp, p);
        dp[0] = max(dp[0], p[0]);
        dp[0] = max(dp[0], p[1] + A[i]*2);
        dp[1] = max(dp[1], p[1]);
        dp[1] = max(dp[1], p[0] + A[i]);
    }

    cout << max(dp[0], dp[1]) << endl;
}