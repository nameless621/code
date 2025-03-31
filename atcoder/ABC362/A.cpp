#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Buy a Pen
//    https://atcoder.jp/contests/abc362/tasks/abc362_a



int main() {
    int R, G, B;
    string C;
    cin >> R >> G >> B >> C;
    
    int ans = 1e9;
    if(C == "Red") ans = min(G, B);
    if(C == "Green") ans = min(R, B);
    if(C == "Blue") ans = min(R, G);

    cout << ans << endl;
}