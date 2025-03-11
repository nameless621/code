#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Which is ahead?
//    https://atcoder.jp/contests/abc342/tasks/abc342_b



int main() {
    int N;
    cin >> N;

    vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        int P;
        cin >> P, P--;
        pos[P] = i;
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        cout << (pos[A] < pos[B] ? A+1 : B+1) << endl;
    }
}