#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Past ABCs
//    https://atcoder.jp/contests/abc350/tasks/abc350_a



int main() {
    string S;
    cin >> S;

    int num = stoi(S.substr(3));
    if(0 < num && num <= 349 && num != 316) cout << "Yes" << endl;
    else cout << "No" << endl;
}