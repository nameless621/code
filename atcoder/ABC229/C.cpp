#include <bits/stdc++.h>
using namespace std;


//    C - Cheese
//    https://atcoder.jp/contests/abc229/tasks/abc229_c



int main() {
    int N, W;
    cin >> N >> W;

    vector<pair<long long, long long>> cheese(N);
    for(int i = 0; i < N; i++) {
        cin >> cheese[i].first >> cheese[i].second;
    }

    sort(cheese.rbegin(), cheese.rend());
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        auto[A, B] = cheese[i];
        if(B < W) {
            ans += A * B;
            W -= B;
        }
        else {
            ans += A * W;
            break;
        }
    }

    cout << ans << endl;
}