#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Frequency
//    https://atcoder.jp/contests/abc338/tasks/abc338_b



int main() {
    string S;
    cin >> S;

    vector<int> cnt(26);
    for(char c : S) {
        cnt[c - 'a']++;
    }

    int res = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    cout << char('a' + res) << endl;
}