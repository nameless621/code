#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - N-choice question
//    https://atcoder.jp/contests/abc300/tasks/abc300_a



int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];

    cout << find(C.begin(), C.end(), A + B) - C.begin() + 1 << endl;
}