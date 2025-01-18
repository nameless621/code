#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Batters
//    https://atcoder.jp/contests/abc256/tasks/abc256_b



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> M(4);
    int P = 0;
    for(int i = 0; i < N; i++) {
        M[0] = 1;
        for(int j = 3; j >= 0; j--) {
            if(M[j] == 0) continue;
            M[j] = 0;
            if(j + A[i] >= 4) P++;
            else M[j + A[i]] = 1;
        }
    }

    cout << P << endl;
}