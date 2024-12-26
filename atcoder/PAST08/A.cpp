#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - ドリンクバー
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_a



int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ans = min(A + B - C, D);
    cout << ans << endl;
}