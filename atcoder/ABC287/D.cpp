#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Match or Not
//    https://atcoder.jp/contests/abc287/tasks/abc287_d



int main() {
    string S, T;
    cin >> S >> T;

    int N = T.size();
    auto check = [&]() {
        vector<bool> res(N + 1);
        res[0] = true;
        for(int i = 0; i < N; i++) {
            if(S[i] == T[i] && res[i]) res[i+1] = true;
            if((S[i] == '?' || T[i] == '?') && res[i]) res[i+1] = true;
        }
        return res;
    };

    auto x = check();
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    auto y = check();

    for(int i = 0; i <= N; i++) {
        cout << (x[i] && y[N - i] ? "Yes" : "No") << endl;
    }
}