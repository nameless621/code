#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - qwerty
//    https://atcoder.jp/contests/abc218/tasks/abc218_b



int main() {
    int P[26];
    for(int i = 0; i < 26; i++) cin >> P[i], P[i]--;

    for(int i = 0; i < 26; i++) cout << char(P[i] + 'a');
    cout << endl;
}