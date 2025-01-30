#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Swap Odd and Even
//    https://atcoder.jp/contests/abc293/tasks/abc293_a



int main() {
    string S;
    cin >> S;

    int N = S.size();
    for(int i = 0; i < N / 2; i++) {
        swap(S[i * 2], S[i * 2 + 1]);
    }

    cout << S << endl;
}