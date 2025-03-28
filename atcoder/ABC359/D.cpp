#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Avoid K Palindrome
//    https://atcoder.jp/contests/abc359/tasks/abc359_d



bool kaibun(string s) { 
    return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    map<string, mint> dp;
    dp[""] = 1;
    for(int i = 0; i < N; i++) {
        map<string, mint> p;
        swap(dp, p);
        for(auto[t, val] : p) {
            for(char c = 'A'; c <= 'B'; c++) {
                if(S[i] != '?' && S[i] != c) continue;
                string nex = t + c;
                if((int)nex.size() == K) {
                    if(kaibun(nex)) continue;
                    nex.erase(nex.begin());
                    dp[nex] += val;
                }
                else {
                    dp[nex] += val;
                }
            }
        }
    }

    mint ans = 0;
    for(auto[t, val] : dp) ans += val;
    cout << ans.val() << endl;
}