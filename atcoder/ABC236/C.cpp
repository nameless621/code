#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Route Map
//    https://atcoder.jp/contests/abc236/tasks/abc236_c



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    set<string> T;
    for(int i = 0; i < M; i++) {
        string str;
        cin >> str;
        T.insert(str);
    }

    for(int i = 0; i < N; i++) {
        cout << (T.count(S[i]) ? "Yes" : "No") << endl;
    }
}