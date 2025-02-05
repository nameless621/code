#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - racecar
//    https://atcoder.jp/contests/abc307/tasks/abc307_b



bool kaibun(string s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    bool ok = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(kaibun(S[i] + S[j])) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}