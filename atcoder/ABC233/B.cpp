#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - A Reverse
//    https://atcoder.jp/contests/abc233/tasks/abc233_b



int main() {
    int L, R;
    string S;
    cin >> L >> R >> S;

    L--;
    reverse(S.begin() + L, S.begin() + R);
    cout << S << endl;
}