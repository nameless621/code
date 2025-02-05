#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Rotate
//    https://atcoder.jp/contests/abc309/tasks/abc309_b



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    char temp = S[1][0];
    swap(S[0][0], temp);
    int i = 0, j = 1, k = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while(i != 0 || j != 0) {
        swap(S[i][j], temp);
        i += dx[k];
        j += dy[k];
        if(i < 0 || i >= N || j < 0 || j >= N) {
            i -= dx[k];
            j -= dy[k];
            k++;
            i += dx[k];
            j += dy[k];
        }
    }

    for(int i = 0; i < N; i++) cout << S[i] << endl;
}