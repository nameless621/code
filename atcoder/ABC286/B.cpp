#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Cat
//    https://atcoder.jp/contests/abc286/tasks/abc286_b



int main() {
    int N;
    string S;
    cin >> N >> S;

    string res;
    for(int i = 0; i < N; i++) {
        res += S[i];
        if((int)res.size() < 2) continue;
        int len = res.size();
        if(res[len-2] == 'n' && res[len-1] == 'a') {
            res.pop_back();
            res += "ya";
        }
    }

    cout << res << endl;
}