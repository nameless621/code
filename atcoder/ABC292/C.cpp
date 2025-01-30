#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Four Variables
//    https://atcoder.jp/contests/abc292/tasks/abc292_c



int f(int x) {
    int res = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i) continue;
        res++;
        if(x / i != i) res++;
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    long long ans = 0;
    for(int i = 1; i < N; i++) {
        long long x = f(i);
        long long y = f(N - i);
        ans += x * y;
    }

    cout << ans << endl;
}