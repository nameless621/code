#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Takahashi's Solitaire
//    https://atcoder.jp/contests/abc277/tasks/abc277_d



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    map<int, vector<int>> mp;
    long long tot = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]].push_back(i);
        tot += A[i];
    }

    dsu d(N);
    for(auto[k, vec] : mp) {
        int x = vec[0], key = k;
        if(d.leader(x) != x) continue;
        for(int y : vec) d.merge(x, y);
        while(mp.count((key+1) % M)) {
            if(d.same(x, mp[(key+1) % M][0])) break;
            for(int y : mp[(key+1) % M]) d.merge(x, y);
            key++;
        }
    }

    long long INF = LLONG_MAX / 2;
    vector<long long> sum(N, -INF);
    for(int i = 0; i < N; i++) {
        int L = d.leader(i);
        if(sum[L] == -INF) sum[L] = A[i];
        else sum[L] += A[i];
    }

    cout << tot - *max_element(sum.begin(), sum.end()) << endl;
}