#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - 2-variable Function
//    https://atcoder.jp/contests/abc246/tasks/abc246_d



long long check(long long a, long long b) {
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main() {
    long long N;
    cin >> N;

    long long ans = LLONG_MAX;
    for(int a = 0; a <= 1e6; a++) {
        int ng = -1, ok = 1e6;
        while(abs(ok - ng) > 1) {
            int b = (ok + ng) / 2;
            if(check(a, b) >= N) ok = b;
            else ng = b;
        }

        ans = min(ans, check(a, ok));
    }

    cout << ans << endl;
}