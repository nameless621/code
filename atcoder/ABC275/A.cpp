#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Find Takahashi
//    https://atcoder.jp/contests/abc275/tasks/abc275_a



int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];

    cout << max_element(H.begin(), H.end()) - H.begin() + 1 << endl;
}