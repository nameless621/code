#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - AtCoder Quiz 2
//    https://atcoder.jp/contests/abc219/tasks/abc219_a



int main() {
    int X;
    cin >> X;

    if(X < 40) cout << 40 - X << endl;
    else if(X < 70) cout << 70 - X << endl;
    else if(X < 90) cout << 90 - X << endl;
    else cout << "expert" << endl;
}