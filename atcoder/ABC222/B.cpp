#include <bits/stdc++.h>
using namespace std;


//    B - Failing Grade
//    https://atcoder.jp/contests/abc222/tasks/abc222_b



int main() {
    int N, P;
    cin >> N >> P;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a < P) cnt++;
    }

    cout << cnt << endl;
}