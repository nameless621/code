#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    F - ダブルブッキング
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_f



int main() {
    int N, M = 1e5 + 9;
    cin >> N;

    vector<vector<int>> Schedule(M, vector<int>(25));
    for(int i = 0; i < N; i++) {
        int D, S, T;
        cin >> D >> S >> T;
        Schedule[D][S]++;
        Schedule[D][T]--;
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 24; j++) {
            Schedule[i][j+1] += Schedule[i][j];
        }
    }

    int ok = false;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 25; j++) {
            if(Schedule[i][j] > 1) {
                ok = true;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}