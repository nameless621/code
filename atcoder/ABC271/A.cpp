#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - 484558
//    https://atcoder.jp/contests/abc271/tasks/abc271_a



string bn(int x, int n) {
    if(x == 0) return "0";
    string s = "";
    string b = "0123456789ABCDEF";
    while(x) {
        s = b[(x % n)] + s;
        x /= n;
    }
    return s;
}

int main() {
    int N;
    cin >> N;

    string res = bn(N, 16);
    while((int)res.size() < 2) res = "0" + res;
    cout << res << endl;
}