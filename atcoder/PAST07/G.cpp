#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    G - べき表現
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_g



int main() {
    long long N;
    cin >> N;

    vector<long long> X;
    long long num = 1;
    while(num < 1e18) {
        X.push_back(num);
        num *= 3;
    }

    reverse(X.begin(), X.end());
    vector<long long> ans;
    for(long long A : X) {
        if(abs(N + A) < abs(N)) {
            N += A;
            ans.push_back(-A);
        }
        else if(abs(N - A) < abs(N)) {
            N -= A;
            ans.push_back(A);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}