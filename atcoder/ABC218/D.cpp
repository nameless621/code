#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Rectangles 
//    https://atcoder.jp/contests/abc218/tasks/abc218_d



int main() {
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    set<pair<int, int>> S;
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        S.emplace(X[i], Y[i]);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(X[i] == X[j] || Y[i] == Y[j]) continue;
            if(S.count({X[i], Y[j]}) && S.count({X[j], Y[i]})) ans++;
        }
    }

    cout << ans / 2 << endl;
}