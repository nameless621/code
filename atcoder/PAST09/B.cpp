#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - 穴の開いた硬貨
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_b



int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        int C = B - A;
        C %= 500;
        C %= 100;
        ans += C / 50;
        C %= 50;
        C %= 10;
        ans += C / 5;
    }

    cout << ans << endl;
}