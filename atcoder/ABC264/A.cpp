#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - "atcoder".substr()
//    https://atcoder.jp/contests/abc264/tasks/abc264_a



int main() {
    string S = "atcoder";
    int L, R;
    cin >> L >> R;
    cout << S.substr(L-1, R - L + 1) << endl;
}