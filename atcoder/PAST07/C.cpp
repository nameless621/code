#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - 入力チェック
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_c



int main() {
    string S;
    int L, R;
    cin >> S >> L >> R;
    
    if((S.size() > 1 && S[0] == '0') || S.size() > to_string(R).size()) {
        cout << "No" << endl;
        return 0;
    }

    int X = stoi(S);
    if(L <= X && X <= R) cout << "Yes" << endl;
    else cout << "No" << endl;
}