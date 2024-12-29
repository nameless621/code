#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Pizza 
//    https://atcoder.jp/contests/abc238/tasks/abc238_b



int main() {
    int N;
    cin >> N;
    
    vector<int> deg = {0};
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        deg.push_back((deg.back() + A) % 360);
    }

    deg.push_back(360);
    sort(deg.begin(), deg.end());

    int ans = 0;
    for(int i = 0; i < N + 1; i++) {
        ans = max(ans, deg[i + 1] - deg[i]);
    }

    cout << ans << endl;
}
