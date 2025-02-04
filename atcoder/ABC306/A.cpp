#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Echo
//    https://atcoder.jp/contests/abc306/tasks/abc306_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    for(char c : S) {
        cout << c << c;
    }
    cout << endl;
}