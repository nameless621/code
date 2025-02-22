#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Take ABC
//    https://atcoder.jp/contests/abc328/tasks/abc328_d



int main() {
    string S;
    cin >> S;

    int N = S.size();
    string T;
    for(int i = 0; i < N; i++) {
        T += S[i];
        int M = T.size();
        if(M < 3) continue;
        if(T.substr(M-3, 3) == "ABC") {
            T.pop_back();
            T.pop_back();
            T.pop_back();
        }
    }

    cout << T << endl;
}