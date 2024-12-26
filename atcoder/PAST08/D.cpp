#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - 約数
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_d



int func(int N) {
    int result = 0;
    for(int i = 1; i * i <= N; i++) {
        if(N % i != 0) continue;
        result++;
        if(N / i != i) result++;
    }
    return result;
}

int main() {
    int X, Y;
    cin >> X >> Y;

    int resX = func(X), resY = func(Y);
    if(resX > resY) cout << 'X' << endl;
    else if(resX < resY) cout << 'Y' << endl;
    else cout << 'Z' << endl;
}