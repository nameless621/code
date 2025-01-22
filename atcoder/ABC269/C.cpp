#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Submask
//    https://atcoder.jp/contests/abc269/tasks/abc269_c



int main() {
    long long N;
    cin >> N;

    vector<long long> ans = {0};
    for(int k = 0; k < 60; k++) {
        if(~N >> k & 1) continue;
        int len = ans.size();
        for(int i = 0; i < len; i++) {
            ans.push_back(ans[i] | 1ll << k);
        }
    }

    for(long long num : ans) cout << num << endl;
}