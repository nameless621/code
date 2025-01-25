#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Let's Get a Perfect Score
//    https://atcoder.jp/contests/abc282/tasks/abc282_b



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int cnt = 0;
            for(int k = 0; k < M; k++) {
                if(S[i][k] == 'o' || S[j][k] == 'o') cnt++;
            }
            if(cnt == M) ans++;
        }
    }

    cout << ans << endl;
}