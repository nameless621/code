#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Souvenirs
//    https://atcoder.jp/contests/abc358/tasks/abc358_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int& a : A) cin >> a;
    for(int& b : B) cin >> b;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    long long ans = 0;
    while(A.size() && B.size()) {
        int a = A.back(), b = B.back();
        if(b <= a) {
            ans += a;
            A.pop_back();
            B.pop_back();
        }
        else {
            A.pop_back();
        }
    }

    cout << (B.size() ? -1 : ans) << endl;
}