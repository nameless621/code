#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Measure
//    https://atcoder.jp/contests/abc319/tasks/abc319_b



int main() {
    int N;
    cin >> N;

    for(int i = 0; i <= N; i++) {
        if(i == 0) {
            cout << 1;
            continue;
        }
        int res = -1;
        for(int j = 1; j <= 9; j++) {
            if(N % j) continue;
            if(i % (N / j) == 0) {
                res = j;
                break;
            }
        }
        if(res == -1) cout << '-';
        else cout << res;
    }
    cout << endl;
}