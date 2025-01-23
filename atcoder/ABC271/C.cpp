#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Manga
//    https://atcoder.jp/contests/abc271/tasks/abc271_c



int main() {
    int N;
    cin >> N;

    set<int> s;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    int ans = 0, cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(s.count(i)) cnt++;
        else cnt += 2;
        if(cnt > N) break;
        ans = i;
    }

    cout << ans << endl;
}