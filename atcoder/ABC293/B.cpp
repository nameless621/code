#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Call the ID Number
//    https://atcoder.jp/contests/abc293/tasks/abc293_b



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    vector<bool> ok(N);
    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        ok[A[i]] = true;
    }

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for(int num : ans) cout << num << " ";
    cout << endl;
}