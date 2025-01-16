#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - At Most 3 (Contestant ver.)
//    https://atcoder.jp/contests/abc250/tasks/abc251_d



int main() {
    int W;
    cin >> W;
    
    vector<int> ans;
    for(int i = 1; i <= 100; i++) {
        ans.push_back(i);
        ans.push_back(i * 100);
        ans.push_back(i * 10000);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int num : ans) cout << num << " ";
    cout << endl;
}