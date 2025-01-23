#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Divide by 2 or 3
//    https://atcoder.jp/contests/abc276/tasks/abc276_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int g = 0;
    for(int i = 0; i < N; i++) g = gcd(g, A[i]);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        A[i] /= g;
        while(A[i] % 2 == 0) {
            ans++;
            A[i] /= 2;
        }
        while(A[i] % 3 == 0) {
            ans++;
            A[i] /= 3;
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if(A[i] != A[i + 1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}