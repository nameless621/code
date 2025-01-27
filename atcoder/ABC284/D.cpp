#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Happy New Year 2023
//    https://atcoder.jp/contests/abc284/tasks/abc284_d



int main() {
    int T;
    cin >> T;

    while(T--) {
        long long N;
        cin >> N;

        long long p = -1, q = -1;
        for(int i = 2; i * i * i <= N; i++) {
            if(N % i) continue;
            if(N / i % i == 0) {
                p = i;
                q = N / i / i;
            }
            else {
                p = sqrt(N / i);
                q = i;
            }
            break;
        }

        cout << p << " " << q << endl;
    }
}