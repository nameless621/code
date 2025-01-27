#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - abc285_brutmhyhiizp
//    https://atcoder.jp/contests/abc285/tasks/abc285_c



long long f(const string& s, long long n) {
    long long x = 0;
    long long base = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        x += (s[i] - 'A' + 1) * base;
        base *= n;
    }
    return x;
}

int main() {
    string S;
    cin >> S;

    long long res = f(S, 26);
    cout << res << endl;
}