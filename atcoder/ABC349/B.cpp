#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Commencement 
//    https://atcoder.jp/contests/abc349/tasks/abc349_b



int main() {
    string S;
    cin >> S;

    vector<int> cnt1(26);
    for(char c : S) cnt1[c - 'a']++;

    vector<int> cnt2(101);
    for(int i = 0; i < 26; i++) cnt2[cnt1[i]]++;

    bool ok = true;
    for(int i = 1; i < 101; i++) {
        if(cnt2[i] == 0 || cnt2[i] == 2) continue;
        ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}