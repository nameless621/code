#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - LOWER
//    https://atcoder.jp/contests/abc314/tasks/abc314_d



int main() {
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    int idx = -1;
    vector<tuple<int, int, char>> query;
    for(int i = 0; i < Q; i++) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        query.emplace_back(t, x - 1, c);
        if(t == 2 || t == 3) idx = i;
    }

    for(int i = 0; i < Q; i++) {
        auto[t, x, c] = query[i];
        if(t == 1) {
            S[x] = c;
        }
        else if(i == idx) {
            for(int k = 0; k < N; k++) {
                if(t == 2) S[k] = tolower(S[k]);
                else S[k] = toupper(S[k]);
            }
        }
    }

    cout << S << endl;
}