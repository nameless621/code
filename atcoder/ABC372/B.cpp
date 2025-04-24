#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - 3^A
//    https://atcoder.jp/contests/abc372/tasks/abc372_b



int main() {
    int M;
    cin >> M;

    vector<int> ans;
    while(M > 0) {
        int A = 0;
        while(M >= pow(3, A+1)) A++;
        ans.push_back(A);
        M -= pow(3, A);
    }

    cout << ans.size() << endl;
    for(int A : ans) cout << A << " ";
    cout << endl;
}