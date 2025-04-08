#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Dividing Game
//    https://atcoder.jp/contests/abc368/tasks/abc368_f



vector<int> build_spff(int n) {
    vector<int> spf(n+1);
    for (int i = 0; i <= n; i++) spf[i] = i;
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i*i; j <= n; j += i)
                spf[j] = min(spf[j], i);
        }
    }
    return spf;
}

vector<int> E(int n) {
    vector<int> res(n+1, 0);
    auto spf = build_spff(n);
    for (int i = 2; i <= n; i++) {
        int x = i;
        while(x > 1) {
            int p = spf[x];
            while(x % p == 0){
                res[i]++;
                x /= p;
            }
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    int sum = 0;
    auto ret = E(1e5);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        sum ^= ret[A];
    }

    cout << (sum != 0 ? "Anna" : "Bruno") << endl;
}