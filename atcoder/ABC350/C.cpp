#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Sort
//    https://atcoder.jp/contests/abc350/tasks/abc350_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a, a--;

    vector<pair<int, int>> res;
    for(int i = 0; i < N; i++) {
        while(A[i] != i) {
            res.emplace_back(i, A[i]);
            swap(A[i], A[A[i]]);
        }
    }

    cout << res.size() << endl;
    for(auto[i, j] : res) {
        cout << i+1 << " " << j+1 << endl;
    }
}