#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Longest Uncommon Prefix
//    https://atcoder.jp/contests/abc285/tasks/abc285_b



int main() {
    int N;
    string S;
    cin >> N >> S;

    for(int i = 1; i < N; i++) {
        int res = 0;
        for(int k = 0; k + i < N; k++) {
            if(S[k] == S[k + i]) break;
            res++;
        }
        cout << res << endl;
    }
}