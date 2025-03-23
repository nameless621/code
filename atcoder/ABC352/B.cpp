#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Typing
//    https://atcoder.jp/contests/abc352/tasks/abc352_b



int main() {
    string S, T;
    cin >> S >> T;

    int j = 0;
    for(int i = 0; i < (int)T.size(); i++) {
        if(T[i] == S[j]) {
            cout << i+1 << " ";
            j++;
        }
    }
    cout << endl;
}