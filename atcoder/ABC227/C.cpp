#include <bits/stdc++.h>
using namespace std;


//    C - ABC conjecture
//    https://atcoder.jp/contests/abc227/tasks/abc227_c



int main() {
    long long N;
    cin >> N;

    long long ans = 0;
    for(long long A = 1; A * A * A <= N; A++) {
        for(long long B = A; A * B * B <= N; B++) {
            long long C = N / (A * B);
            ans += C - B + 1;
        }
    }

    cout << ans << endl;
}