#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - TLD
//    https://atcoder.jp/contests/abc339/tasks/abc339_a



int main() {
    string S;
    cin >> S;

    string T = S.substr(S.rfind('.')+1);
    cout << T << endl;
}