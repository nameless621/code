#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Decrease 2 max elements
//    https://atcoder.jp/contests/abc368/tasks/abc368_b



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    sort(A.rbegin(), A.rend());

    int ans = 0;
    while(A[0] > 0 && A[1] > 0) {
        A[0]--;
        A[1]--;
        sort(A.rbegin(), A.rend());
        ans++;
    }

    cout << ans << endl;
}