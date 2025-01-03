#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Weather Forecast
//    https://atcoder.jp/contests/abc218/tasks/abc218_a



int main() {
    int N;
    string S;
    cin >> N >> S;
    N--;
    cout << (S[N] == 'o' ? "Yes" : "No") << endl;
}