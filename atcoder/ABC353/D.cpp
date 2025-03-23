#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Another Sigma Problem 
//    https://atcoder.jp/contests/abc353/tasks/abc353_d



int main() {
    int N;
    cin >> N;

    long long sum = 0;
    vector<int> A(N);
    vector<int> cnt(11);
    for(int& a : A) {
        cin >> a;
        sum += a;
        cnt[to_string(a).size()]++;
    }

    mint ans = 0;
    for(int i = 0; i < N; i++) {
        cnt[to_string(A[i]).size()]--;
        sum -= A[i];
        ans += sum;
        for(int j = 1; j < 11; j++) {
            ans += mint(10).pow(j) * cnt[j] * A[i];
        }
    }

    cout << ans.val() << endl;
}