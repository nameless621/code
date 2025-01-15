#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Lacked Number
//    https://atcoder.jp/contests/abc248/tasks/abc248_a



int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    for(int i = 0; i < 9; i++) {
        if(S[i] - '0' != i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 9 << endl;
}