#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Chinese Restaurant
//    https://atcoder.jp/contests/abc268/tasks/abc268_c



int main() {
    int N;
    cin >> N;

    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    vector<int> cnt(N);
    for(int i = 0; i < N; i++) {
        if(i < p[i]) {
            cnt[p[i] - i]++;
            cnt[p[i] - i + 1]++;
            cnt[p[i] - i - 1]++;
        }
        if(i == p[i]) {
            cnt[0]++;
            cnt[1]++;
            cnt[N-1]++;
        }
        if(i > p[i]) {
            cnt[(N - i - 1) + p[i]]++;
            cnt[(N - i - 1) + p[i] + 1]++;
            cnt[(N - i - 1) + p[i] + 2]++;
        }
    }

    cout << *max_element(cnt.begin(), cnt.end()) << endl;
}