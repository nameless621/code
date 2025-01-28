#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Marking
//    https://atcoder.jp/contests/abc290/tasks/abc290_d



int main() {
    int T;
    cin >> T;
    while(T--) {
        long long N, D, K;
        cin >> N >> D >> K;
        K--;
        long long X = N / gcd(N, D);
        cout << K * D % N + K / X << endl;
    }
}