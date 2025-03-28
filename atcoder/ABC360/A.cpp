#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - A Healthy Breakfast
//    https://atcoder.jp/contests/abc360/tasks/abc360_a



int main() {
    string S;
    cin >> S;

    int i = S.find('R');
    int j = S.find('M');

    if(i < j) cout << "Yes" << endl;
    else cout << "No" << endl;
}