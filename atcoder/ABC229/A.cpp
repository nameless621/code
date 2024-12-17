#include <bits/stdc++.h>
using namespace std;


//    A - First Grid
//    https://atcoder.jp/contests/abc229/tasks/abc229_a



int main() {
    string S1, S2;
    cin >> S1 >> S2;
    bool ok = true;
    if(S1[0] == S2[1] && S1[0] == '.') ok = false;
    if(S1[1] == S2[0] && S1[1] == '.') ok = false;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}