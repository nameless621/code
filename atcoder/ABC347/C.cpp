#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Ideal Holidays
//    https://atcoder.jp/contests/abc347/tasks/abc347_c



int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<long> D(N);
    for(int i = 0; i < N; i++) {
        cin >> D[i];
        D[i] %= A + B;
    } 

    sort(D.begin(), D.end());
    for(int i = 0; i < N; i++) {
        D.push_back(D[i] + A + B);
    }

    N *= 2;
    bool ok = false;
    for(int i = 0; i < N-1; i++) {
        if(D[i+1] - D[i] > B) {
            ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}