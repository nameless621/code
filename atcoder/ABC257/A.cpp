#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - A to Z String 2
//    https://atcoder.jp/contests/abc257/tasks/abc257_a



int main() {
    int N, X;
    cin >> N >> X;
    X--;
    string res;
    for(char c = 'A'; c <= 'Z'; c++) {
        res += string(N, c);
    }
    cout << res[X] << endl;
}
