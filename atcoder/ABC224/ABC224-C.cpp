#include <bits/stdc++.h>
using namespace std;


//    C - Triangle?
//    https://atcoder.jp/contests/abc224/tasks/abc224_c



int main() {
    int N;
    cin >> N;
    vector<long long> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                if((X[i] - X[k]) * (Y[j] - Y[k]) - (X[j] - X[k]) * (Y[i] - Y[k]) != 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}