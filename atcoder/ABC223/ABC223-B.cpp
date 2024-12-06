#include <bits/stdc++.h>
using namespace std;


//https://atcoder.jp/contests/abc223/tasks/abc223_b


int main() {
    string S;
    cin >> S;

    auto T = S;
    set<string> result;
    result.insert(S);
    
    for(int i = 0; i < (int)S.size(); i++) {
        rotate(S.begin(), S.begin() + 1, S.end());
        rotate(T.rbegin(), T.rbegin() + 1, T.rend());
        result.insert(S);
        result.insert(T);
    }

    cout << *result.begin() << endl;
    cout << *result.rbegin() << endl;
}