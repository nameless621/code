#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Collision 2
//    https://atcoder.jp/contests/abc243/tasks/abc243_c



int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    string S;
    cin >> S;

    map<int, vector<int>> L, R;
    for(int i = 0; i < N; i++) {
        auto[x, y] = P[i];
        if(S[i] == 'L') L[y].push_back(x);
        else R[y].push_back(x);
    }

    for(auto&[k, v] : L) sort(v.begin(), v.end());

    bool ok = false;
    for(auto&[k, v] : R) {
        if(!L.count(k)) continue;
        for(int x : v) {
            auto itr = lower_bound(L[k].begin(), L[k].end(), x);
            if(itr != L[k].end()) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}