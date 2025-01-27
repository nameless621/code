#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Sequence of Strings
//    https://atcoder.jp/contests/abc284/tasks/abc284_a



int main() {
    int N;
    cin >> N;
    
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = N-1; i >= 0; i--) cout << S[i] << endl;
}