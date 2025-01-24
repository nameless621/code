#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Shift
//    https://atcoder.jp/contests/abc278/tasks/abc278_a



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < K; i++) {
        A.erase(A.begin());
        A.push_back(0);
    }

    for(int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
}