#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Mismatched Parentheses
//    https://atcoder.jp/contests/abc307/tasks/abc307_d



int main() {
    int N;
    string S;
    cin >> N >> S;

    int cnt = 0;
    string res;
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') {
            res += S[i];
            cnt++;
        }
        else if(S[i] == ')' && cnt) {
            if(cnt) {
                while(res.back() != '(') res.pop_back();
                res.pop_back();
                cnt--;
            }
        }
        else res += S[i];
    }

    cout << res << endl;
}