#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Mex
//    https://atcoder.jp/contests/abc245/tasks/abc245_b



int main() {
    int N;
    cin >> N;

    set<int> S;
    for(int i = 0; i <= N; i++) {
        S.insert(i);
    }

    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        S.erase(A);
    }

    cout << *S.begin() << endl;
}