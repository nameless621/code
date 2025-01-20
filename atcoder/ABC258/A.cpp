#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - When?
//    https://atcoder.jp/contests/abc254/tasks/abc258_a



int main() {
    int K;
    cin >> K;

    int HH = 21 + (K >= 60 ? 1 : 0);
    int MM = K % 60;
    cout << HH << ':';
    if(MM < 10) cout << 0;
    cout << MM << endl;
}