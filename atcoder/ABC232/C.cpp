#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Graph Isomorphism
//    https://atcoder.jp/contests/abc232/tasks/abc232_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        A[X][Y] = A[Y][X] = 1;
    }
    for(int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        B[X][Y] = B[Y][X] = 1;
    }

    vector<int> P(N);
    iota(P.begin(), P.end(), 0);

    bool ok = false;
    do {
        vector<vector<int>> res(N, vector<int>(N));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                res[i][j] = A[P[i]][P[j]];
            }
        }
        if(res == B) ok = true;
    } while(next_permutation(P.begin(), P.end()));

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}