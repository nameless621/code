#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Select Mul
//    https://atcoder.jp/contests/abc221/tasks/abc221_c



int main() {
    long long N;
    cin >> N;

    vector<int> P;
    while(N > 0) {
        P.push_back(N % 10);
        N /= 10;
    }

    sort(P.rbegin(), P.rend());
    int m = 1 << (int)P.size();
    long long ans = 0;
    for(int bit = 0; bit < m; bit++) {
        long long x = 0, y = 0;
        for(int i = 0; i < (int)P.size(); i++) {
            if(bit >> i & 1) x = x * 10 + P[i];
            else y = y * 10 + P[i];
        }
        ans = max(ans, x * y);
    }

    cout << ans << endl;
}