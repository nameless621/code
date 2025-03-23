#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Remove Pairs
//    https://atcoder.jp/contests/abc354/tasks/abc354_e



int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    int N2 = 1 << N;
    vector<bool> dp(N2);
    for(int S = 0; S < N2; S++) {
        bool flag = false;
        for(int i = 0; i < N; i++) {
            if(~S >> i & 1) continue;
            for(int j = i+1; j < N; j++) {
                if(~S >> j & 1) continue;
                if(A[i] != A[j] && B[i] != B[j]) continue;
                if(!dp[S ^ (1 << i) ^ (1 << j)]) flag = true;
            }
        }
        dp[S] = flag;
    }

    cout << (dp[N2-1] ? "Takahashi" : "Aoki") << endl;
}