#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - A Recursive Function
//    https://atcoder.jp/contests/abc273/tasks/abc273_a



int f(int k) {
    if(k == 0) return 1;
    return k * f(k - 1);
}

int main() {
    int N;
    cin >> N;
    cout << f(N) << endl;
}