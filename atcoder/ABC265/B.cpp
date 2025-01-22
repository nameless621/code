#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Explore
//    https://atcoder.jp/contests/abc265/tasks/abc265_b



int main() {
    int N, M;
    long long T;
    cin >> N >> M >> T;

    vector<int> A(N);
    for(int i = 1; i < N; i++) cin >> A[i];

    vector<int> X(N);
    for(int i = 0; i < M; i++) {
        int pos, Y;
        cin >> pos >> Y;
        X[pos - 1] = Y;
    }

    bool ok = true;
    for(int i = 1; i < N; i++) {
        T -= A[i];
        if(T <= 0) {
            ok = false;
            break;
        }
        T += X[i];
    }

    cout << (ok ? "Yes" : "No") << endl;
}