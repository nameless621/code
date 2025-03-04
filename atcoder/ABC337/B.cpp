#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Extended ABC
//    https://atcoder.jp/contests/abc337/tasks/abc337_b



int main() {
    string S;
    cin >> S;

    auto temp = S;
    sort(S.begin(), S.end());
    
    cout << (S == temp ? "Yes" : "No") << endl;
}