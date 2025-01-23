#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Rightmost
//    https://atcoder.jp/contests/abc276/tasks/abc276_a



int main() {
    string S;
    cin >> S;

    int idx = -1;
    for(int i = 0; i < (int)S.size(); i++) {
        if(S[i] == 'a') idx = i + 1;
    }

    cout << idx << endl;
}