#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Just K
//    https://atcoder.jp/contests/abc249/tasks/abc249_c



int main() {
    int N, K;
    cin >> N >> K;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        vector<int> cnt(26);
        for(int i = 0; i < N; i++) {
            if(~bit >> i & 1) continue;
            for(char c : S[i]) {
                cnt[c - 'a']++;
            }
        }

        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == K) res++;
        }
        
        ans = max(ans, res);
    }

    cout << ans << endl;
}