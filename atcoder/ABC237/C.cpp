#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - kasaka
//    https://atcoder.jp/contests/abc237/tasks/abc237_c



void func(string& S, int& X) {
    while((int)S.size() > 0 && S.back() == 'a') {
        X++;
        S.pop_back();
    }
}

bool kaibun(string s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }

int main() {
    string S;
    cin >> S;

    int L = 0, R = 0;
    func(S, R);
    reverse(S.begin(), S.end());
    func(S, L);

    bool ok = true;
    if(!kaibun(S)) ok = false;
    else if(L > R) ok = false;

    cout << (ok ? "Yes" : "No") << endl;
}