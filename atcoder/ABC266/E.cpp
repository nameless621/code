#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Throwing the Die
//    https://atcoder.jp/contests/abc266/tasks/abc266_e



int main() {
    int N;
    cin >> N;

    vector<double> dp(N+1);
    dp[1] = 3.5;
    for(int i = 2; i <= N; i++) {
        double temp = 0;
        for(double x = 1; x <= 6; x++) {
            temp += max(x, dp[i-1]);
        }
        dp[i] = temp / 6;
    }

    cout << fixed << setprecision(12) << dp[N] << endl;
}