#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Saturday
//    https://atcoder.jp/contests/abc267/tasks/abc267_a



int main() {
    map<string, int> m;
    m["Monday"] = 5;
    m["Tuesday"] = 4;
    m["Wednesday"] = 3;
    m["Thursday"] = 2;
    m["Friday"] = 1;

    string S;
    cin >> S;
    cout << m[S] << endl;
}