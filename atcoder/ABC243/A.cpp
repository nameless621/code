#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Shampoo
//    https://atcoder.jp/contests/abc243/tasks/abc243_a



int main() {
    int V, S[3];
    cin >> V >> S[0] >> S[1] >> S[2];

    vector<char> C = {'F', 'M', 'T'};
    int i = 0;
    while(1) {
        V -= S[i];
        if(V < 0) break;
        i = (i + 1) % 3;
    }

    cout << C[i] << endl;
}