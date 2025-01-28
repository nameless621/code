#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Step Up Robot
//    https://atcoder.jp/contests/abc289/tasks/abc289_d



int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int M;
    cin >> M;
    vector<bool> ng(1e5+1);
    for(int i = 0; i < M; i++) {
        int B;
        cin >> B;
        ng[B] = true;
    }

    int X;
    cin >> X;

    vector<bool> dp(X + 1);
    dp[0] = true;
    for(int i = 0; i <= X; i++) {
        if(!dp[i]) continue;
        for(int j = 0; j < N; j++) {
            if(i + A[j] > X || ng[i + A[j]]) continue;
            dp[i + A[j]] = true;
        }
    }

    cout << (dp[X] ? "Yes" : "No") << endl;
}