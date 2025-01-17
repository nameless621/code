#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Together Square
//    https://atcoder.jp/contests/abc254/tasks/abc254_d



long long nC2(long long n) { return n * (n - 1) / 2; }

int main() {
    int N;
    cin >> N;

    map<int, int> cnt;
    for(int i = 1; i <= N; i++) {
        int x = i;
        vector<int> res;
        for(int p = 2; p * p <= x; p++) {
            if(x % p) continue;
            int e = 0;
            while(x % p == 0) {
                x /= p;
                e++;
            }
            if(e & 1) res.push_back(p);
        }
        if(x > 1) res.push_back(x);
        int s = 1;
        for(int num : res) s *= num;
        cnt[s]++;
    }

    long long ans = N;
    for(auto[k, v] : cnt) {
        ans += nC2(v) * 2;
    }

    cout << ans << endl;
}