#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Spoiler
//    https://atcoder.jp/contests/abc344/tasks/abc344_a



int main() {
    string S;
    cin >> S;
    int l = S.find('|');
    int r = S.rfind('|');
    S.erase(S.begin()+l, S.begin()+r+1);
    cout << S << endl;
}