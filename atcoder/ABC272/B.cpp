#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Everyone is Friends
//    https://atcoder.jp/contests/abc272/tasks/abc272_b



int main() {
    int N, M;
    cin >> N >> M;
    
    set<pair<int, int>> s;
    for(int i = 0; i < M; i++) {
        int k;
        cin >> k;
        vector<int> x(k);
        for(int j = 0; j < k; j++) {
            cin >> x[j];
        }
        for(int j = 0; j < k; j++) {
            for(int l = j + 1; l < k; l++) {
                s.insert({x[j], x[l]});
            }
        }
    }

    bool ok = true;
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(!s.count({i, j})) {
                ok = false;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}