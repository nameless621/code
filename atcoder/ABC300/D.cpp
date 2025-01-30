#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - AABCC
//    https://atcoder.jp/contests/abc300/tasks/abc300_d



vector<long long> E(int n) {
    vector<bool> isprime(n+1, true);
    vector<long long> prime;
    isprime[0] = isprime[1] = false;
    for (int p = 2; p <= n; ++p) {
        if (!isprime[p]) continue;
        prime.push_back(p);
        for (int q = p * 2; q <= n; q += p) isprime[q] = false;
    }
    return prime;
}

int main() {
    long long N;
    cin >> N;

    auto P = E(1e6);
    int M = P.size();
    int ans = 0;
    for(int i = 0; i < M; i++) {
        if(P[i] * P[i] > N) break;
        for(int j = i+1; j < M; j++) {
            if(P[i] * P[i] * P[j] > N) break;
            for(int k = j+1; k < M; k++) {
                long long sum = P[i] * P[i] * P[j];
                if(sum * P[k] > N) break;
                if(sum * P[k] * P[k] > N) break;
                ans++;
            }
        }
    }

    cout << ans << endl;
}