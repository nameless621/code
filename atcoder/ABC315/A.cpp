#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - tcdr
//    https://atcoder.jp/contests/abc315/tasks/abc315_a



int main() {
    string S;
    cin >> S;

    string ng = "aiueo";
    string res;
    for(char c : S) {
        if(ng.find(c) == string::npos) res += c;
    }

    cout << res << endl;
}