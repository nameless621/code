#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Choose Two and Eat One 
//    https://atcoder.jp/contests/abc282/tasks/abc282_e



using T = tuple<int, int, int>;

long long modpow(long long x, long long n, long long mod) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ((ret%mod)*(x%mod))%mod;
        x = ((x%mod)*(x%mod))%mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    priority_queue<T> pq;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int cost = (modpow(A[i], A[j], M) + modpow(A[j], A[i], M)) % M;
            pq.emplace(cost, i, j);
        }
    }

    dsu uf(N);
    long long ans = 0;
    while(!pq.empty()) {
        auto[cost, i, j] = pq.top();
        pq.pop();
        if(uf.same(i, j)) continue;
        uf.merge(i, j);
        ans += cost;
    }

    cout << ans << endl;
}