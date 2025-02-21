#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - ab
//    https://atcoder.jp/contests/abc327/tasks/abc327_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    if(S.find("ab") != string::npos || S.find("ba") != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;
}