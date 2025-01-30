#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Three Days Ago
//    https://atcoder.jp/contests/abc295/tasks/abc295_d



int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        A[i] = 1 << (S[i] - '0');
    }

    vector<int> prefix_xor(N + 1);
    for(int i = 0; i < N; i++) {
        prefix_xor[i+1] = prefix_xor[i] ^ A[i];
    }

    map<int, int> cnt;
    long long ans = 0;
    for(int i = 0; i < N + 1; i++) {
        ans += cnt[prefix_xor[i]];
        cnt[prefix_xor[i]]++;
    }

    cout << ans << endl;
}