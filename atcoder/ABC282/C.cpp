#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - String Delimiter
//    https://atcoder.jp/contests/abc282/tasks/abc282_c



int main() {
    int N;
    string S;
    cin >> N >> S;

    bool flag = false;
    for(int i = 0; i < N; i++) {
        if(S[i] == '"') flag = !flag;
        if(S[i] == ',' && !flag) S[i] = '.';
    }

    cout << S << endl;
}