#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - 343 
//    https://atcoder.jp/contests/abc343/tasks/abc343_c



bool kaibun(string S) { 
    int N = S.size();
    for(int i = 0; i < N / 2; i++) {
        if(S[i] != S[N - i - 1]) return false;
    }
    return true;
}

int main() {
    long long N;
    cin >> N;

    long long ans = 0;
    for(long long x = 1; x * x * x <= N; x++) {
        long long K = x * x * x;
        if(kaibun(to_string(K))) ans = K;
    }

    cout << ans << endl;
}