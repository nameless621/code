#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Tile Distance 2
//    https://atcoder.jp/contests/abc359/tasks/abc359_c



int main() {
    long long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    if((Sx + Sy) & 1) Sx--;
    if((Tx + Ty) & 1) Tx--;
    
    long long dx = abs(Sx - Tx);
    long long dy = abs(Sy - Ty);

    cout << (dy + max(dx, dy)) / 2 << endl;
}