#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Paint
//    https://atcoder.jp/contests/abc346/tasks/abc346_e



int main() {
    int H, W, M;
    cin >> H >> W >> M;

    vector<int> T(M), A(M), X(M);
    for(int i = 0; i < M; i++) {
        cin >> T[i] >> A[i] >> X[i];
        A[i]--;
    }

    vector<bool> tate(W), yoko(H);
    map<int, long long> cnt;
    cnt[0] += (long long)H * W;
    for(int i = M-1; i >= 0; i--) {
        if(T[i] == 1 && !yoko[A[i]] && W > 0) {
            yoko[A[i]] = true;
            cnt[0] -= W;
            cnt[X[i]] += W;
            H--;
        }
        if(T[i] == 2 && !tate[A[i]] && H > 0) {
            tate[A[i]] = true;
            cnt[0] -= H;
            cnt[X[i]] += H;
            W--;
        }
    }

    if(cnt[0] == 0) cnt.erase(0);
    cout << cnt.size() << endl;
    for(auto[k, v] : cnt) {
        cout << k << " " << v << endl;
    }
}