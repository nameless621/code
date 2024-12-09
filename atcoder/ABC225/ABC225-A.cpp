#include <bits/stdc++.h>
using namespace std;


//    A - Distinct Strings
//    https://atcoder.jp/contests/abc225/tasks/abc225_a



int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    set<string> res;
    do {
        res.insert(S);
    } while(next_permutation(S.begin(), S.end()));
    cout << res.size() << endl;
}