#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - A Gift From the Stars 
//    https://atcoder.jp/contests/abc303/tasks/abc303_e



int main() {
    int N;
    cin >> N;

    vector<int> deg(N);
    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        deg[a]++;
        deg[b]++;
    }

    vector<int> ans;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(deg[i] < 3) continue;
        ans.push_back(deg[i]);
        sum += deg[i] + 1;
    }

    int rem = (N - sum) / 3;
    while(rem--) ans.push_back(2);
    sort(ans.begin(), ans.end());
    for(int res : ans) cout << res << " ";
    cout << endl;
}