#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Rotate and Palindrome
//    https://atcoder.jp/contests/abc286/tasks/abc286_c



int main() {
    int N;
    long long A, B;
    string S;
    cin >> N >> A >> B >> S;

    long long ans = LLONG_MAX;
    for(int i = 0; i < N; i++) {
        long long sum = A * i;
        for(int i = 0; i < N / 2; i++) {
            if(S[i] != S[N - i - 1]) {
                sum += B;
            }
        }
        ans = min(ans, sum);
        rotate(S.begin(), S.begin() + 1, S.end());
    }

    cout << ans << endl;
}