#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Multi Test Cases
//    https://atcoder.jp/contests/abc284/tasks/abc284_b



int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int res = 0;
        for(int i = 0; i < N; i++) {
            int A;
            cin >> A;
            if(A & 1) res++;
        }

        cout << res << endl;
    }
}