#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Append
//    https://atcoder.jp/contests/abc340/tasks/abc340_b



int main() {
    int Q;
    cin >> Q;

    vector<int> A;
    while(Q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            A.push_back(x);
        }
        if(t == 2) {
            int k;
            cin >> k;
            cout << A[A.size() - k] << endl;
        }
    }
}