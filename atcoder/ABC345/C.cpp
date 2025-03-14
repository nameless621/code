#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - One Time Swap
//    https://atcoder.jp/contests/abc345/tasks/abc345_c



int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<int> cnt(26);
    for(int i = 0; i < N; i++) {
        cnt[S[i] - 'a']++;
    }

    long long ans = 0;
    bool flag = false;
    for(int i = 0; i < N; i++) {
        cnt[S[i] - 'a']--;
        for(int j = 0; j < 26; j++) {
            if(j == S[i] - 'a') {
                if(cnt[S[i] - 'a']) flag = true;
                continue;
            }
            else {
                ans += cnt[j];
            }
        }
    }

    if(flag) ans++;
    cout << ans << endl;
}