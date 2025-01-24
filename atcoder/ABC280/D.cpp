#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Factorial and Multiple
//    https://atcoder.jp/contests/abc280/tasks/abc280_d



long long f(long long n, long long P) {
    if(n / P == 0) return 0;
    return n / P + (f(n / P, P));
}

int main() {
    long long K;
    cin >> K;

    map<long long, int> cnt;
    for(long long p = 2; p*p <= K; p++) {
        if(K % p) continue;
        int e = 0;
        while(K % p == 0) {
            K /= p;
            e++;
        }
        cnt[p] = e;
    }
    if(K != 1) cnt[K] = 1;

    auto check = [&](long long n) {
        for(auto[P, val] : cnt) {
            if(f(n, P) < val) return false;
        }
        return true;
    };

    long long ng = 0, ok = 1e18;
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}