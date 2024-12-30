#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Digit Machine
//    https://atcoder.jp/contests/abc241/tasks/abc241_a



int main() {
    int a[10];
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }

    int now = 0;
    for(int i = 0; i < 3; i++) {
        now = a[now];
    }

    cout << now << endl;
}