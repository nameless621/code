#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Chord
//    https://atcoder.jp/contests/abc312/tasks/abc312_a



int main() {
    vector<string> t = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

    string S;
    cin >> S;
    
    if(find(t.begin(), t.end(), S) != t.end()) cout << "Yes" << endl;
    else cout << "No" << endl;
}