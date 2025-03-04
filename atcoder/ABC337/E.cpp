#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Bad Juice 
//    https://atcoder.jp/contests/abc337/tasks/abc337_e



int main() {
    int N;
    cin >> N;

    int M = 0;
    while(N > (1 << M)) M++;
    cout << M << endl;

    for(int i = 0; i < M; i++) {
        vector<int> res;
        for(int k = 0; k < N; k++) {
            if(k >> i & 1) res.push_back(k+1);
        }
        cout << res.size() << " ";
        for(int num : res) cout << num << " ";
        cout << endl;
    }

    string S;
    cin >> S;

    int ans = 0;
    for(int i = 0; i < M; i++) {
        if(S[i] == '1') ans |= 1 << i;
    }
    cout << ans+1 << endl;
}