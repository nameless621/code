#include <bits/stdc++.h>
using namespace std;


//    D - Longest X
//    https://atcoder.jp/contests/abc229/tasks/abc229_d



int main() {
    string S;
    int K;
    cin >> S >> K;

    int N = S.size();
    vector<int> cnt(N + 1);
    for(int i = 0; i < N; i++) {
        if(S[i] == '.') cnt[i + 1] = cnt[i] + 1;
        else cnt[i + 1] = cnt[i];
    }

    int ans = 0, r = 0;
    for(int l = 0; l <= N; l++) {
        r = max(l, r);
        while(r + 1 <= N && cnt[r + 1] - cnt[l] <= K) {
            r++;
        }
        ans = max(ans, r - l);
    }

    cout << ans << endl;
}