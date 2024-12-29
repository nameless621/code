#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Exponential or Quadratic
//    https://atcoder.jp/contests/abc238/tasks/abc238_a



int main() {
    long long n;
    cin >> n;

    long long two = 1;
    int cnt = 0;
    bool ok = false;
    while(two <= n * n && cnt < n) {
        cnt++;
        two *= 2;
        if(two > n * n) ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
