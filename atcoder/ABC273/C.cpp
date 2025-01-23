#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - (K+1)-th Largest Number
//    https://atcoder.jp/contests/abc273/tasks/abc273_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    auto B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<int> cnt(N);
    for(int i = 0; i < N; i++) {
        int res = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        cnt[B.size() - res]++;
    }

    for(int i = 0; i < N; i++) {
        cout << cnt[i] << endl;
    }
}