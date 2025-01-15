#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Perfect String
//    https://atcoder.jp/contests/abc249/tasks/abc249_b



int main() {
    string S;
    cin >> S;

    set<char> seen;
    bool f1 = true, f2 = false, f3 = false;
    for(char c : S) {
        if(seen.count(c)) f1 = false;
        seen.insert(c);
        if(islower(c)) f2 = true;
        if(isupper(c)) f3 = true;
    }

    cout << (f1 && f2 && f3 ? "Yes" : "No") << endl;
}