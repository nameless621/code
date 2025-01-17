#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - ±1 Operation 1
//    https://atcoder.jp/contests/abc255/tasks/abc255_c



int main() {
    long long X, A, D, N;
    cin >> X >> A >> D >> N;
    
    if(D == 0) {
        cout << abs(A - X) << endl;
        return 0;
    }
    
    if(D < 0) {
        A = A + D * (N - 1);
        D = -D;
    }

    long long i = (X - A) / D;
    auto f = [&](long long i) {
        if(i < 0) i = 0;
        if(i >= N) i = N - 1;
        return A + D * i;
    };

    long long ans = abs(f(i) - X);
    ans = min(ans, abs(f(i + 1) - X));
    cout << ans << endl;
}