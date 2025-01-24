#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Freefall
//    https://atcoder.jp/contests/abc279/tasks/abc279_d



int main() {
    long long A, B;
    cin >> A >> B;

    auto f = [&](double g) {
        return (double)B * g + (double)A / sqrt(g + 1);
    };

    long long l = 0, r = A / B;
    int cnt = 100;
    while(cnt--) {
        long long mid1 = l + (r - l) / 3;
        long long mid2 = r - (r - l) / 3;
        if(f(mid1) < f(mid2)) r = mid2;
        else l = mid1;
    }

    double ans = A;
    for(long long i = l; i <= r; i++) {
        ans = min(ans, f(i));
    }

    cout << fixed << setprecision(12) << ans << endl;
}