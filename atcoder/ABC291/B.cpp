#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Trimmed Mean
//    https://atcoder.jp/contests/abc291/tasks/abc291_b



int main() {
    int N;
    cin >> N;

    vector<int> X(5 * N);
    for(int i = 0; i < 5 * N; i++) cin >> X[i];

    sort(X.begin(), X.end());
    double sum = 0;
    for(int i = N; i < 4 * N; i++) sum += X[i];

    cout << fixed << setprecision(12) << sum / (3 * N) << endl;
}