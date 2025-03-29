#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Intersection of Cuboids
//    https://atcoder.jp/contests/abc361/tasks/abc361_b



bool func(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2)-max(l1, l2));
}

int main() {
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;

    bool ret1 = func(a, d, g, j);
    bool ret2 = func(b, e, h, k);
    bool ret3 = func(c, f, i, l);
    
    if(ret1 && ret2 && ret3) cout << "Yes" << endl;
    else cout << "No" << endl;
}