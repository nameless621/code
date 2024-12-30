#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Prime Sum Game
//    https://atcoder.jp/contests/abc239/tasks/abc239_d



bool isprime(int x) {
    for(int i = 2; i*i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    bool ok = false;
    for(int i = A; i <= B; i++) {
        bool flag = true;
        for(int j = C; j <= D; j++) {
            if(isprime(i + j)) flag = false;
        }
        if(flag) ok = true;
    }

    cout << (ok ? "Takahashi" : "Aoki") << endl;
}