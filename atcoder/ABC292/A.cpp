#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - CAPS LOCK
//    https://atcoder.jp/contests/abc292/tasks/abc292_a



int main() {
    string S;
    cin >> S;

    for(char& c : S) {
        c = toupper(c);
    }

    cout << S << endl;
}