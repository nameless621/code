#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Weird Function
//    https://atcoder.jp/contests/abc234/tasks/abc234_a



int f(int x) {
    return x * x + 2 * x + 3;
}

int main() {
    int t;
    cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
}