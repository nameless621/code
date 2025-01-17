#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - You should output ARC, though this is ABC. 
//    https://atcoder.jp/contests/abc255/tasks/abc255_a



int main() {
    int R, C;
    cin >> R >> C;
    R--;
    C--;

    int A[2][2];
    cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
    cout << A[R][C] << endl;
}