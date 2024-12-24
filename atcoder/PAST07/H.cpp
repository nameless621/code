#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    H - 折れ線グラフ
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_h



int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    double INF = DBL_MAX;
    vector dp(N, vector(101, vector<double>(sum+1, INF)));
    dp[0][0][0] = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= 100; j++) {
            for(int k = 0; k <= sum; k++) {
                if(dp[i][j][k] == INF) continue;
                for(int nex = 0; nex <= 100; nex++) {
                    if(k + nex > sum) break;
                    int x1 = i+1, y1 = j;
                    int x2 = i+2, y2 = nex;
                    double X = x1 - x2;
                    double Y = y1 - y2;
                    double D = sqrt(X * X + Y * Y);
                    dp[i+1][nex][k + nex] = min(dp[i+1][nex][k + nex], dp[i][j][k] + D);
                }
            }
        }
    }

    cout << fixed << setprecision(12) << dp[N-1][0][sum] << endl;
}