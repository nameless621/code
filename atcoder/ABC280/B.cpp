#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Inverse Prefix Sum
//    https://atcoder.jp/contests/abc280/tasks/abc280_b



int main() {
    int N;
    cin >> N;

    vector<long long> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    long long sum = 0;
    for(int i = 0; i < N; i++) {
        long long res = S[i] - sum;
        sum += res;
        cout << res << " ";
    }
    cout << endl;
}