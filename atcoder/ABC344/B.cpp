#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Delimiter
//    https://atcoder.jp/contests/abc344/tasks/abc344_b



int main() {
    vector<int> A;
    int num;
    while(cin >> num) {
        A.push_back(num);
    }

    reverse(A.begin(), A.end());
    for(int num : A) cout << num << endl;
}