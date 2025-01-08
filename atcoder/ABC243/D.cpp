#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Moves on Binary Tree
//    https://atcoder.jp/contests/abc243/tasks/abc243_d



int main() {
    int N;
    long long X;
    string S;
    cin >> N >> X >> S;

    string now = bitset<64>(X).to_string();
    for(int i = 0; i < N; i++) {
        if(S[i] == 'U') now.pop_back();
        if(S[i] == 'L') now += '0';
        if(S[i] == 'R') now += '1';
    }

    long long ans = 0;
    reverse(now.begin(), now.end());
    for(int i = 0; i < (int)now.size(); i++) {
        if(now[i] == '1') ans |= 1ll << i;
    }

    cout << ans << endl;
}