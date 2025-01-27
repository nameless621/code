#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Range Swap
//    https://atcoder.jp/contests/abc286/tasks/abc286_a



int main() {
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    P--; Q--; R--; S--;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    auto B = A;
    auto f = [&](int x, int y, int z) {
        int j = z;
        for(int i = x; i <= y; i++) {
            B[j] = A[i];
            j++;
        }
    };
    
    f(P, Q, R);
    f(R, S, P);

    for(int i = 0; i < N; i++) {
        cout << B[i] << " ";
        if(i == N - 1) cout << endl;
    }
}