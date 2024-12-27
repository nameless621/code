#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - 試験
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    vector<tuple<int, int, int>> P;
    for(int i = 0; i < N; i++) {
        P.emplace_back(A[i] + B[i], A[i], -i);
    }

    sort(P.rbegin(), P.rend());
    for(int i = 0; i < N; i++) {
        auto[ab, a, idx] = P[i];
        cout << -idx + 1 << " ";
    }
    cout << endl;
}