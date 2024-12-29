#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - AND and SUM
//    https://atcoder.jp/contests/abc238/tasks/abc238_d



int main() {
    int T;
    cin >> T;
    while(T--) {
        long long a, s;
        cin >> a >> s;
        long long b = s - a * 2;
        if(a & b || b < 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
