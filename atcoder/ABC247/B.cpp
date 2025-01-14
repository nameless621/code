#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Unique Nicknames
//    https://atcoder.jp/contests/abc247/tasks/abc247_b



int main() {
    int N;
    cin >> N;

    vector<string> s(N), t(N);
    map<string, int> cnt;
    for(int i = 0; i < N; i++) {
        cin >> s[i] >> t[i];
        cnt[s[i]]++;
        cnt[t[i]]++;
    }

    bool ok = true;
    for(int i = 0; i < N; i++) {
        if(s[i] != t[i] && cnt[s[i]] > 1 && cnt[t[i]] > 1) ok = false;
        else if(cnt[s[i]] > 2) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}