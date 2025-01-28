#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - flip
//    https://atcoder.jp/contests/abc289/tasks/abc289_a



int main() {
    string S;
    cin >> S;
    
    for(char c : S) {
        cout << (c == '0' ? 1 : 0);
    }
    cout << endl;
}