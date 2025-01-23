#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Integer Sum 
//    https://atcoder.jp/contests/abc272/tasks/abc272_a



int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        ans += A;
    }

    cout << ans << endl;
}