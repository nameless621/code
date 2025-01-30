#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Socks 
//    https://atcoder.jp/contests/abc295/tasks/abc295_c



int main() {
    int N;
    cin >> N;
    
    map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cnt[A]++;
    }

    int ans = 0;
    for(auto[k, v] : cnt) {
        ans += v / 2;
    }

    cout << ans << endl;
}