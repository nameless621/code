#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Find Multiple
//    https://atcoder.jp/contests/abc220/tasks/abc220_a



int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int ans = -1;
    for(int i = A; i <= B; i++) {
        if(i % C == 0) ans = i;
    }

    cout << ans << endl;
}