#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Raise Both Hands
//    https://atcoder.jp/contests/abc370/tasks/abc370_a



int main() {
    int L, R;
    cin >> L >> R;

    if(L && !R) cout << "Yes" << endl;
    else if(!L && R) cout << "No" << endl;
    else cout << "Invalid" << endl;
}