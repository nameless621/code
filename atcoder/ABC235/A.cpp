#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Rotate
//    https://atcoder.jp/contests/abc235/tasks/abc235_a



int f(int x) {
    return x * 100 + x * 10 + x;
}

int main() {
    string S;
    cin >> S;

    int ans = f(S[0] - '0');
    ans += f(S[1] - '0');
    ans += f(S[2] - '0');

    cout << ans << endl;
}