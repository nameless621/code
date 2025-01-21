#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Min Max Pair
//    https://atcoder.jp/contests/abc262/tasks/abc262_c



int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }

    long long ans = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        if(i == a[i]) cnt++;
        else if (i == a[a[i]]) ans++;
    }

    ans = ans / 2 + cnt * (cnt - 1) / 2;
    cout << ans << endl;
}
