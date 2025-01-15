#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - 250-like Number
//    https://atcoder.jp/contests/abc250/tasks/abc250_d



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

    auto p = E(1e6);
    int ans = 0, len = p.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            long long q = p[j] * p[j] * p[j];
            if(p[i] > N / q) break;
            ans++;
        }
    }

    cout << ans << endl;
}