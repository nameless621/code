#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - XX to XXX
//    https://atcoder.jp/contests/abc259/tasks/abc259_c



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
    string S, T;
    cin >> S >> T;

    auto A = RLE(S);
    auto B = RLE(T);
    if(A.size() != B.size()) {
        cout << "No" << endl;
        return 0;
    }

    bool ok = true;
    for(int i = 0; i < (int)A.size(); i++) {
        if(A[i].first != B[i].first) ok = false;
        if(A[i].second > B[i].second) ok = false;
        if(A[i].second == 1 && B[i].second > 1) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
