#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Count Subtractions
//    https://atcoder.jp/contests/abc297/tasks/abc297_d



int main() {
    long long A, B;
    cin >> A >> B;

    long long ans = 0;
    while(A != B) {
        if(A > B) swap(A, B);
        if(B % A == 0) {
            ans += B / A - 1;
            break;
        }
        ans += B / A;
        B %= A;
    }

    cout << ans << endl;
}