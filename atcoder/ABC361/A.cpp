#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Insert
//    https://atcoder.jp/contests/abc361/tasks/abc361_a



int main() {
    int N, K, X;
    cin >> N >> K >> X;
    
    vector<int> A(N);
    for(int& a : A) cin >> a;

    A.insert(A.begin() + K, X);
    for(int a : A) cout << a << " ";
    cout << endl;
}