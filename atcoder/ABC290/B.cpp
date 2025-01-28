#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Qual B
//    https://atcoder.jp/contests/abc290/tasks/abc290_b



int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    for(int i = 0; i < N; i++) {
        if(S[i] == 'x') continue;
        if(K > 0) K--;
        else S[i] = 'x';
    }

    cout << S << endl;
}