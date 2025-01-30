#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Treasure Chest
//    https://atcoder.jp/contests/abc299/tasks/abc299_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    bool flag = false;
    for(int i = 0; i < N; i++) {
        if(S[i] == '|') flag = !flag;
        if(S[i] == '*' && flag) {
            cout << "in" << endl;
            return 0;
        }
    }

    cout << "out" << endl;
}