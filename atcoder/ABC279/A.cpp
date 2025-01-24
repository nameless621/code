#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - wwwvvvvvv
//    https://atcoder.jp/contests/abc279/tasks/abc279_a



int main() {
    string S;
    cin >> S;
    int ans = 0;
    for(char c : S) {
        if(c == 'v') ans++;
        else ans += 2;
    }
    cout << ans << endl;
}