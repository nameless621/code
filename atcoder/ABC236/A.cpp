#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - chukodai 
//    https://atcoder.jp/contests/abc236/tasks/abc236_a



int main() {
    string S;
    int a, b;
    cin >> S >> a >> b;
    a--; b--;
    swap(S[a], S[b]);
    cout << S << endl;
}