#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Spot the Difference
//    https://atcoder.jp/contests/abc351/tasks/abc351_b



int main() {
    int N;
    cin >> N;

    vector<string> A(N), B(N);
    for(auto& a : A) cin >> a;
    for(auto& b : B) cin >> b;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] != B[i][j]) {
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
}