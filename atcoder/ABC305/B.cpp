#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - ABCDEFG
//    https://atcoder.jp/contests/abc305/tasks/abc305_b



int main() {
    vector<int> a = {0, 3, 4, 8, 9, 14, 23};

    char p, q;
    cin >> p >> q;
    int x = p - 'A', y = q - 'A';
    if(x > y) swap(x, y);
    cout << a[y] - a[x] << endl;
}