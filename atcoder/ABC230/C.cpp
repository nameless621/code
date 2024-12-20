#include <bits/stdc++.h>
using namespace std;


//    C - X drawing
//    https://atcoder.jp/contests/abc230/tasks/abc230_c



int main() {
    long long N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;

    for(long long i = P; i <= Q; i++) {
        for(long long j = R; j <= S; j++) {
            bool flag = false;
            if(i - A == j - B) flag = true;
            if(i - A == B - j) flag = true;
            cout << (flag ? '#' : '.');
        }
        cout << endl;
    }
}