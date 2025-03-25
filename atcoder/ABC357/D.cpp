#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - 88888888 
//    https://atcoder.jp/contests/abc357/tasks/abc357_d



int main() {
    long long N;
    cin >> N;

    mint r = mint(10).pow(to_string(N).size());
    mint ans = mint(N) * (1 - r.pow(N)) / (1 - r);
    cout << ans.val() << endl;
}