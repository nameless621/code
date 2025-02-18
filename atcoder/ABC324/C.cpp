#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Error Correction
//    https://atcoder.jp/contests/abc324/tasks/abc324_c



int main() {
    int N;
    string T;
    cin >> N >> T;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int lenT = T.size();
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        int lenS = S[i].size();
        bool ok = false;
        if(T == S[i]) ok = true;
        else if(lenT == lenS) {
            int cnt = 0;
            for(int j = 0; j < lenS; j++) {
                if(T[j] != S[i][j]) cnt++;
            }
            if(cnt == 1) ok = true;
        }
        else if(lenT == lenS + 1) {
            int idx = 0, cnt = 0;
            for(int j = 0; j < lenT; j++) {
                if(T[j] != S[i][idx]) cnt++;
                else idx++;
                if(idx == lenS) break;
            }
            if(cnt <= 1) ok = true;
        }
        else if(lenT + 1 == lenS) {
            int idx = 0, cnt = 0;
            for(int j = 0; j < lenS; j++) {
                if(S[i][j] != T[idx]) cnt++;
                else idx++;
                if(idx == lenT) break;
            }
            if(cnt <= 1) ok = true;
        }
        if(ok) ans.push_back(i+1);
    }

    cout << ans.size() << endl;
    for(int num : ans) cout << num << " ";
    cout << endl;
}