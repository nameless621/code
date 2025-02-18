#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Joint Two Strings
//    https://atcoder.jp/contests/abc324/tasks/abc324_e



int main() {
    int N;
    string T;
    cin >> N >> T;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int len = T.size();
    vector<int> pre(len + 1), suf(len + 1);
    for(int i = 0; i < N; i++) {
        int idx = 0;
        for(int j = 0; j < (int)S[i].size(); j++) {
            if(S[i][j] == T[idx]) idx++;
            if(idx == len) break;
        }
        pre[idx]++;

        idx = len - 1;
        for(int j = (int)S[i].size() - 1; j >= 0; j--) {
            if(S[i][j] == T[idx]) idx--;
            if(idx < 0) break;
        }
        suf[len - idx - 1]++;
    }
    
    vector<long long> sum(len + 2);
    for(int i = 0; i < len + 1; i++) {
        sum[i+1] = sum[i] + suf[i];
    }

    long long ans = 0;
    for(int i = 0; i < len + 1; i++) {
        int l = len - i, r = len + 1;
        long long res = sum[r] - sum[l];
        ans += (long long)pre[i] * res;
    }

    cout << ans << endl;
}