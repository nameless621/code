#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Rook Score
//    https://atcoder.jp/contests/abc298/tasks/abc298_f



int main() {
    int N;
    cin >> N;

    vector<int> R(N), C(N), X(N);
    for(int i = 0; i < N; i++) {
        cin >> R[i] >> C[i] >> X[i];
    }

    auto tempR = R;
    auto tempC = C;
    sort(tempR.begin(), tempR.end());
    sort(tempC.begin(), tempC.end());

    vector<long long> tate(N), yoko(N);
    vector<vector<int>> pos(N);
    map<pair<int, int>, int> M;
    for(int i = 0; i < N; i++) {
        R[i] = lower_bound(tempR.begin(), tempR.end(), R[i]) - tempR.begin();
        C[i] = lower_bound(tempC.begin(), tempC.end(), C[i]) - tempC.begin();
        tate[C[i]] += X[i];
        yoko[R[i]] += X[i];
        pos[R[i]].push_back(C[i]);
        M[{R[i], C[i]}] = X[i];
    }

    multiset<long long> S;
    S.insert(0);
    for(int i = 0; i < N; i++) {
        S.insert(tate[i]);
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j : pos[i]) {
            ans = max(ans, yoko[i] + tate[j] - M[{i, j}]);
            S.erase(S.find(tate[j]));
        }
        ans = max(ans, yoko[i] + *prev(S.end()));
        for(int j : pos[i]) {
            S.insert(tate[j]);
        }
    }

    cout << ans << endl;
}