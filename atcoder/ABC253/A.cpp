#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Median?
//    https://atcoder.jp/contests/abc253/tasks/abc253_a



int main() {
    vector<int> num(3);
    cin >> num[0] >> num[1] >> num[2];
    int b = num[1];
    sort(num.begin(), num.end());
    cout << (num[1] == b ? "Yes" : "No") << endl;
}