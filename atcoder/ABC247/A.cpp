#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Move Right
//    https://atcoder.jp/contests/abc247/tasks/abc247_a



int main() {
    string S;
    cin >> S;
    bitset<4> bit(S);
    bit >>= 1;
    cout << bit << endl;
}