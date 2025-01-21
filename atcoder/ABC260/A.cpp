#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - A Unique Letter
//    https://atcoder.jp/contests/abc260/tasks/abc260_a



int main() {
    string S;
    cin >> S;

    vector<int> cnt(26);
    for(int i = 0; i < 3; i++) {
        cnt[S[i] - 'a']++;
    }

    auto itr = find(cnt.begin(), cnt.end(), 1);
    if(itr == cnt.end()) cout << -1 << endl;
    else cout << char('a' + (itr - cnt.begin())) << endl;
}
