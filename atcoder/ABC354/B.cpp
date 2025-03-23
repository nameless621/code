#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - AtCoder Janken 2
//    https://atcoder.jp/contests/abc354/tasks/abc354_b



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    int T = 0;
    for(int i = 0; i < N; i++) {
        int C;
        cin >> S[i] >> C;
        T += C;
    }

    sort(S.begin(), S.end());
    cout << S[T % N] << endl;
}