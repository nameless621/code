#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - (∀x∀)
//    https://atcoder.jp/contests/abc242/tasks/abc242_e



using mint = modint998244353;

void solve() {
    int N;
    string S;
    cin >> N >> S;

    int len = (N + 2 - 1) / 2;
    mint ans = 0;
    for(int i = 0; i < len; i++) {
        ans += (S[i] - 'A') * mint(26).pow(len - i - 1);
    }
    
    string L = S.substr(0, len);
    string temp = L;
    if(N & 1) temp.pop_back();
    reverse(temp.begin(), temp.end());
    L += temp;
    if(L <= S) ans++;
    
    cout << ans.val() << endl;
};

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}