#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Triple Attack
//    https://atcoder.jp/contests/abc368/tasks/abc368_c



int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int& h : H) cin >> h;

    long long T = 0;
    for(int i = 0; i < N; i++) {
        int cnt = H[i] / 5;
        T += cnt * 3;
        H[i] %= 5;
        while(H[i] > 0) {
            T++;
            if(T % 3 == 0) H[i] -= 3;
            else H[i]--;
        }
    }

    cout << T << endl;
}