#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Happy New Year!
//    https://atcoder.jp/contests/abc234/tasks/abc234_c



string bn(long long x, long long n) {
    if(x == 0) return "0";
    string s = "";
    while(x) {
        s = to_string(x % n) + s;
        x /= n;
    }
    return s;
}

int main() {
    long long K;
    cin >> K;
    string result = bn(K, 2);
    for(char c : result) cout << (c == '1' ? 2 : 0);
    cout << endl;
}