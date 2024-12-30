#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Jumping Takahashi 
//    https://atcoder.jp/contests/abc240/tasks/abc240_c



int main() {
    int N, X;
    cin >> N >> X;

    bitset<10101> dp;
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        bitset<10101> p;
        swap(dp, p);
        dp |= (p << a) | (p << b);
    }

    cout << (dp[X] ? "Yes" : "No") << endl;
}