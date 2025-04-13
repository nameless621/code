#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Logical Filling
//    https://atcoder.jp/contests/abc401/tasks/abc401_d



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
    int N, K;
    string S;
    
    cin >> N >> K >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            cnt++;
            if(0 < i && S[i-1] == '?') S[i-1] = '.';
            if(i+1 < N && S[i+1] == '?') S[i+1] = '.';
        }
    }

    if(cnt == K) {
        for(int i = 0; i < N; i++) {
            if(S[i] == '?') S[i] = '.';
        }
        cout << S << endl;
        return 0;
    }

    auto ret = RLE(S);
    for(auto[c, val] : ret) {
        if(c == '?') cnt += (val + 1) / 2;
    }

    if(cnt == K) {
        string res;
        for(auto[c, val] : ret) {
            if(c != '?') res += string(val, c);
            else {
                if(val & 1) {
                    for(int i = 0; i < val; i++) {
                        if(~i & 1) res += 'o';
                        else res += '.';
                    }
                }
                else res += string(val, '?');
            }
        }
        cout << res << endl;
    }
    else cout << S << endl;
}