#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Caesar Cipher
//    https://atcoder.jp/contests/abc232/tasks/abc232_b



int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size();
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        A[i] = S[i] - 'a';
        B[i] = T[i] - 'a';
    }

    bool ok = false;
    for(int k = 0; k <= 26; k++) {
        vector<int> res(N);
        for(int i = 0; i < N; i++) {
            res[i] = (A[i] + k) % 26;
        }
        if(res == B) ok = true;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}