#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Flip and Adjust
//    https://atcoder.jp/contests/abc271/tasks/abc271_d



int main() {
    int N, S;
    cin >> N >> S;
    
    vector<int> a(N), b(N);
    vector<vector<bool>> dp(N+1, vector<bool>(S+1));
    dp[0][0] = true;
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        for(int j = 0; j < S; j++) {
            if(!dp[i][j]) continue;
            if(j + a[i] <= S) dp[i+1][j + a[i]] = true;
            if(j + b[i] <= S) dp[i+1][j + b[i]] = true;
        }
    }

    if(!dp[N][S]) {
        cout << "No" << endl;
        return 0;
    }

    int now = S;
    string ans;
    for(int i = N - 1; i >= 0; i--) {
        if(now - a[i] >= 0 && dp[i][now - a[i]]) {
            now -= a[i];
            ans += "H";
        }
        else {
            now -= b[i];
            ans += "T";
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "Yes" << endl;
    cout << ans << endl;
}