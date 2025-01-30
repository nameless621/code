#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Double Click
//    https://atcoder.jp/contests/abc297/tasks/abc297_a



int main() {
    int N, D;
    cin >> N >> D;

    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];

    for(int i = 0; i < N - 1; i++) {
        if(T[i+1] - T[i] <= D) {
            cout << T[i+1] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}