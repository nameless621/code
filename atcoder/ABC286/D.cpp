#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Money in Hand 
//    https://atcoder.jp/contests/abc286/tasks/abc286_d



int main() {
    int N, X;
    cin >> N >> X;

    bitset<10101> dp;
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        for(int i = 0; i < B; i++) {
            dp |= dp << A;
        }
    }

    cout << (dp[X] ? "Yes" : "No") << endl;
}