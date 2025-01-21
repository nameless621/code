#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Many Operations
//    https://atcoder.jp/contests/abc254/tasks/abc261_e



int main() {
    int N, C;
    cin >> N >> C;

    vector<int> T(N), A(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i] >> A[i];
    }

    vector<int> ans(N);
    for(int k = 0; k < 30; k++) {
        vector<int> func = {0, 1};
        int crr = C >> k & 1;
        for(int i = 0; i < N; i++) {
            vector<int> f;
            int x = A[i] >> k & 1;
            if(T[i] == 1) f = {0 & 1, 1 & x};
            if(T[i] == 2) f = {0 | x, 1 | x};
            if(T[i] == 3) f = {0 ^ x, 1 ^ x};
            func = {f[func[0]], f[func[1]]};
            crr = func[crr];
            ans[i] |= crr << k;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}