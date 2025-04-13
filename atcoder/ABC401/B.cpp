#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Unauthorized
//    https://atcoder.jp/contests/abc401/tasks/abc401_b



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(string& s : S) cin >> s;

    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < N; i++) {
        if(S[i] == "login") flag = true;
        if(S[i] == "logout") flag = false;
        if(S[i] == "private" && !flag) cnt++;
    }

    cout << cnt << endl;
}