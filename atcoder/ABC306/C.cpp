#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Centers
//    https://atcoder.jp/contests/abc306/tasks/abc306_c



int main() {
    int N;
    cin >> N;

    vector<int> cnt(N);
    vector<pair<int, int>> P;
    for(int i = 0; i < 3*N; i++) {
        int A;
        cin >> A, A--;
        cnt[A]++;
        if(cnt[A] == 2) P.emplace_back(i, A+1);
    }

    sort(P.begin(), P.end());
    for(int i = 0; i < N; i++) {
        cout << P[i].second << " ";
    }
    cout << endl;
}