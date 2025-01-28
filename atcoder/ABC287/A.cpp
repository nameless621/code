#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Majority
//    https://atcoder.jp/contests/abc287/tasks/abc287_a



int main() {
    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if(S == "For") cnt++;
    }

    cout << (cnt >= (N+1)/2 ? "Yes" : "No") << endl;
}