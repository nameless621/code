#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Qualification Contest
//    https://atcoder.jp/contests/abc288/tasks/abc288_b



int main() {
    int N, K;
    cin >> N >> K;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.begin() + K);
    for(int i = 0; i < K; i++) cout << S[i] << endl;
}