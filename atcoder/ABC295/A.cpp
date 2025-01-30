#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Probably English
//    https://atcoder.jp/contests/abc295/tasks/abc295_a



int main() {
    int N;
    cin >> N;

    vector<string> S = {"and", "not", "that", "the", "you"};
    bool ok = false;
    for(int i = 0; i < N; i++) {
        string W;
        cin >> W;
        if(find(S.begin(), S.end(), W) != S.end()) ok = true;
    }

    cout << (ok ? "Yes" : "No") << endl;
}