#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Vertical Writing
//    https://atcoder.jp/contests/abc366/tasks/abc366_b



int main() {
    int N;
    cin >> N;

    int M = 0;
    vector<string> S(N);
    for(auto& s : S) {
        cin >> s;
        M = max(M, (int)s.size());
    }
    reverse(S.begin(), S.end());
    
    vector<string> T;
    for(int j = 0; j < M; j++) {
        string res;
        for(int i = 0; i < N; i++) {
            if((int)S[i].size() <= j) res += '*';
            else res += S[i][j];
        }
        while(res.back() == '*') res.pop_back();
        T.push_back(res);
    }

    for(auto& t : T) {
        cout << t << endl;
    }
}