#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Avoid K Palindrome 2 
//    https://atcoder.jp/contests/abc363/tasks/abc363_c



bool kaibun(string s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    sort(S.begin(), S.end());
    int ans = 0;
    do {
        bool ok = true;
        for(int i = 0; i < N-K+1; i++) {
            if(kaibun(S.substr(i, K))) {
                ok = false;
            }
        }
        if(ok) ans++;
    } while(next_permutation(S.begin(), S.end()));

    cout << ans << endl;
}