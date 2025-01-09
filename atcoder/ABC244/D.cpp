#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Swap Hats
//    https://atcoder.jp/contests/abc244/tasks/abc244_d



int main() {
    char S[3], T[3];
    for(int i = 0; i < 3; i++) cin >> S[i];
    for(int i = 0; i < 3; i++) cin >> T[i];

    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] != T[i]) cnt++;
    }

    if(cnt == 0 || cnt == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}