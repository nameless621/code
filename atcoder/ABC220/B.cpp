#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Base K 
//    https://atcoder.jp/contests/abc220/tasks/abc220_b



long long to_decimal(const string& s, int n) {
    long long x = 0;
    long long base = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        x += (s[i] - '0') * base;
        base *= n;
    }
    return x;
}

int main() {
    int K;
    string A, B;
    cin >> K >> A >> B;

    auto resA = to_decimal(A, K);
    auto resB = to_decimal(B, K);

    cout << resA * resB << endl;
}