#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Vertical Reading
//    https://atcoder.jp/contests/abc360/tasks/abc360_b



int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size();
    bool ok = false;
    for(int c = 0; c < N; c++) {
        for(int w = c+1; w < N; w++) {
            vector<string> res;
            for(int i = 0; i < N; i += w) {
                if(i + w <= N) res.push_back(S.substr(i, w));
                else res.push_back(S.substr(i));
            }
            string ret;
            for(string x : res) {
                if((int)x.size() <= c) continue;
                ret += x[c];
            }
            if(ret == T) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}