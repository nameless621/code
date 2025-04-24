#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - delete .
//    https://atcoder.jp/contests/abc372/tasks/abc372_a



int main() {
    string S;
    cin >> S;

    S.erase(remove(S.begin(), S.end(), '.'), S.end());
    cout << S << endl;
}