#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Uppercase and Lowercase
//    https://atcoder.jp/contests/abc357/tasks/abc357_b



int main() {
    string S;
    cin >> S;

    int N = S.size(), up = 0, low = 0;
    for(int i = 0; i < N; i++) {
        if(isupper(S[i])) up++;
        else low++;
    }

    if(up > low) {
        for(int i = 0; i < N; i++) {
            S[i] = toupper(S[i]);
        }
    }
    else {
        for(int i = 0; i < N; i++) {
            S[i] = tolower(S[i]);
        }
    }

    cout << S << endl;
}