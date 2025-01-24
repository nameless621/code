#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Extra Character
//    https://atcoder.jp/contests/abc280/tasks/abc280_c



int main() {
    string S, T;
    cin >> S >> T;

    for(int i = 0; i < (int)S.size(); i++) {
        if(S[i] != T[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << T.size() << endl;
}