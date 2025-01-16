#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Six Characters
//    https://atcoder.jp/contests/abc250/tasks/abc251_a



int main() {
    string S;
    cin >> S;

    string res;
    while((int)res.size() < 6) res += S;
    cout << res << endl;
}