#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Apple
//    https://atcoder.jp/contests/abc265/tasks/abc265_a



int main() {
    int X, Y, N;
    cin >> X >> Y >> N;

    int ans = min(N * X, Y * (N / 3) + X * (N % 3));
    cout << ans << endl;
}