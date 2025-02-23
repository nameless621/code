#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Count xxx
//    https://atcoder.jp/contests/abc329/tasks/abc329_c



vector<pair<char, int>> RLE(const string& s) {
    int cnt = 1;
    vector<pair<char, int>> res;
    for(int i = 1; i < (int)s.size(); i++) {
        if(s[i] != s[i-1]) {
            res.push_back({s[i-1], cnt});
            cnt = 1;
        }
        else cnt++;
    }
    res.push_back({s[s.size()-1], cnt});
    return res;
}

int main() {
    int N;
    string S;
    cin >> N >> S;

    auto res = RLE(S);
    vector<int> cnt(26);
    for(auto[c, val] : res) {
        cnt[c - 'a'] = max(cnt[c - 'a'], val);
    }

    int ans = accumulate(cnt.begin(), cnt.end(), 0);
    cout << ans << endl;
}