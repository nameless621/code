#include <bits/stdc++.h>
using namespace std;


//    A - Four Digits
//    https://atcoder.jp/contests/abc222/tasks/abc222_a



int main() {
    string N;
    cin >> N;
    N = string(4 - (int)N.size(), '0') + N;
    cout << N << endl;
}