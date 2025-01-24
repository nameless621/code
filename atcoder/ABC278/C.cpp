#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - FF
//    https://atcoder.jp/contests/abc278/tasks/abc278_c



int main() {
    int N, Q;
    cin >> N >> Q;

    map<int, set<int>> FF;
    while(Q--) {
        int T, A, B;
        cin >> T >> A >> B;
        A--; B--;
        if(T == 1) {
            FF[A].insert(B);
        }
        if(T == 2) {
            FF[A].erase(B);
        }
        if(T == 3) {
            bool ok = (FF[A].count(B) && FF[B].count(A));
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
}