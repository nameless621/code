#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Enlarged Checker Board 
//    https://atcoder.jp/contests/abc250/tasks/abc250_b



int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<string> S(A * N, string(B * N, '.'));
    for(int i = 0; i < A * N; i++) {
        for(int j = 0; j < B * N; j++) {
            int x = i / A;
            int y = j / B;
            if((x + y) & 1) S[i][j] = '#';
        }
    }

    for(string s : S) cout << s << endl;
}