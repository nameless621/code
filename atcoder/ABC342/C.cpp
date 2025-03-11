#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Many Replacement
//    https://atcoder.jp/contests/abc342/tasks/abc342_c



int main() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    vector<char> p(26);
    for(char c = 'a'; c <= 'z'; c++) p[c - 'a'] = c;

    while(Q--) {
        char c, d;
        cin >> c >> d;
        for(int i = 0; i < 26; i++) {
            if(p[i] == c) p[i] = d;
        }
    }

    for(int i = 0; i < N; i++) {
        S[i] = p[S[i] - 'a'];
    }
    
    cout << S << endl;
}