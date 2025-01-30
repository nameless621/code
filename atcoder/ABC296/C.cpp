#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Gap Existence
//    https://atcoder.jp/contests/abc296/tasks/abc296_c



int main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    unordered_set<int> S;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        S.insert(A[i]);
    }

    bool ok = false;
    for(int i = 0; i < N; i++) {
        if(S.count(X + A[i])) {
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}