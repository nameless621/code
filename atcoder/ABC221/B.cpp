#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - typo
//    https://atcoder.jp/contests/abc221/tasks/abc221_b



int main() {
    string S, T;
    cin >> S >> T;
    
    bool ok = false;
    for(int i = 0; i < (int)S.size(); i++) {
        swap(S[i], S[i+1]);
        if(S == T) ok = true;
        swap(S[i], S[i+1]);
    }
    
    cout << (ok ? "Yes" : "No") << endl;
}