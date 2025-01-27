#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Cash Register 
//    https://atcoder.jp/contests/abc283/tasks/abc283_c



int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());

    int ans = 0, N = S.size();
    for(int i = 0; i < N; i++) {
        if(i+1 < N && S[i] == '0' && S[i+1] == '0') i++;
        ans++;
    }

    cout << ans << endl;
}