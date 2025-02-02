#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - First Player
//    https://atcoder.jp/contests/abc304/tasks/abc304_a



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i] >> A[i];
    }

    int st = min_element(A.begin(), A.end()) - A.begin();
    for(int i = 0; i < N; i++) {
        int idx = (st + i) % N;
        cout << S[idx] << endl;
    }
}