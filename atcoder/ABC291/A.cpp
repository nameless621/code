#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - camel Case
//    https://atcoder.jp/contests/abc291/tasks/abc291_a



int main() {
    string S;
    cin >> S;

    for(int i = 0; i < (int)S.size(); i++) {
        if(isupper(S[i])) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}