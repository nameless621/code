#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Sandwich Number
//    https://atcoder.jp/contests/abc281/tasks/abc281_b



int main() {
    string S;
    cin >> S;
    if(!isupper(S[0]) || !isupper(S.back()) || S.size() != 8) {
        cout << "No" << endl;
        return 0;
    }

    bool ok = true;
    for(int i = 1; i < 7; i++) {
        if(i == 1 && S[i] == '0') ok = false;
        if(!isdigit(S[i])) {
            ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}