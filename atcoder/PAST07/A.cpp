#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - チェックディジット
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_a



int main() {
    string S;
    cin >> S;

    int N = S.size(), odd = 0, even = 0;
    for(int i = 1; i <= N - 1; i++) {
        int num = S[i - 1] - '0';
        if(i & 1) odd += num;
        else even += num;
    }

    int res = (odd * 3 + even) % 10;
    int num = S.back() - '0';
    if(res == num) cout << "Yes" << endl;
    else cout << "No" << endl;
}