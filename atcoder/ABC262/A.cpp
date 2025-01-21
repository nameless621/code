#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - World Cup
//    https://atcoder.jp/contests/abc254/tasks/abc262_a



int main() {
    int Y;
    cin >> Y;
    int x = Y % 4;
    if(x == 0) Y += 2;
    if(x == 1) Y += 1;
    if(x == 3) Y += 3;
    cout << Y << endl;
}