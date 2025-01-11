#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Good morning 
//    https://atcoder.jp/contests/abc245/tasks/abc245_a



int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    bool flag = false;
    if(A < C) flag = true;
    else if(A == C && B <= D) flag = true;

    cout << (flag ? "Takahashi" : "Aoki") << endl;
}