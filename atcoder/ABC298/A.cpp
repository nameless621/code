#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Job Interview
//    https://atcoder.jp/contests/abc298/tasks/abc298_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    bool ok = false, ng = false;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') ok = true;
        if(S[i] == 'x') ng = true;
    }

    cout << (ng || !ok ? "No" : "Yes") << endl;
}