#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - NewFolder(1) 
//    https://atcoder.jp/contests/abc254/tasks/abc261_c



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    map<string, int> cnt;
    for(int i = 0; i < N; i++) {
        cin >> S[i];
        cnt[S[i]]++;
        if(cnt[S[i]] > 1) {
            S[i] += "(" + to_string(cnt[S[i]] - 1) + ")";
        }
    }

    for(int i = 0; i < N; i++) {
        cout << S[i] << endl;
    }
}