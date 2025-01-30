#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - LRUD Instructions 2
//    https://atcoder.jp/contests/abc291/tasks/abc291_c



int main() {
    int N;
    string S;
    cin >> N >> S;

    bool ok = false;
    int x = 0, y = 0;
    set<pair<int, int>> visited;
    visited.insert({x, y});
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') x++;
        if(S[i] == 'L') x--;
        if(S[i] == 'U') y++;
        if(S[i] == 'D') y--;
        if(visited.count({x, y})) ok = true;
        visited.insert({x, y});
    }

    cout << (ok ? "Yes" : "No") << endl;
}