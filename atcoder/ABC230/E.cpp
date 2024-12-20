#include <bits/stdc++.h>
using namespace std;


//    E - Fraction Floor Sum
//    https://atcoder.jp/contests/abc230/tasks/abc230_e



int main() {
    long long N;
    cin >> N;

    long long ans = N, i = 2, pre = 1;
    while(i <= N) {
        long long now = N / i;
        long long ok = i, ng = N + 1;
        while(abs(ok - ng) > 1) {
            long long mid = (ok + ng) / 2;
            if(N / mid < now) ng = mid;
            else ok = mid;
        }
        ans += now * (ok - pre);
        i = ng;
        pre = ok;
    }

    cout << ans << endl;
}