#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Not Overflow 
//    https://atcoder.jp/contests/abc237/tasks/abc237_a



int main() {
    long long N;
    cin >> N;

    long long M = 1ll << 31;
    if(-M <= N && N < M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}