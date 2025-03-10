#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Print 341
//    https://atcoder.jp/contests/abc341/tasks/abc341_a



int main() {
    int N;
    cin >> N;

    string res = "1";
    for(int i = 0; i < N; i++) {
        res += "01";
    }

    cout << res << endl;
}