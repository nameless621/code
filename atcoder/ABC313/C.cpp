#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Approximate Equalization 2
//    https://atcoder.jp/contests/abc313/tasks/abc313_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    int x = sum / N;
    int y = sum % N;
    vector<int> res(N, x);
    for(int i = 0; i < y; i++) {
        res[i]++;
    }

    sort(A.rbegin(), A.rend());
    
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        ans += abs(res[i] - A[i]);
    }

    ans /= 2;
    cout << ans << endl;
}