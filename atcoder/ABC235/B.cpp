#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Climbing Takahashi
//    https://atcoder.jp/contests/abc235/tasks/abc235_b



int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int now = H[0];
    for(int i = 1; i < N; i++) {
        if(now < H[i]) now = H[i];
        else break;
    }

    cout << now << endl;
}