#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - AtCoder Quiz
//    https://atcoder.jp/contests/abc217/tasks/abc217_b



int main() {
    vector<string> A = {"ABC", "ARC", "AGC", "AHC"};
    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];
    for(int i = 0; i < 4; i++) {
        if(find(S.begin(), S.end(), A[i]) == S.end()) {
            cout << A[i] << endl;
        }
    }
}