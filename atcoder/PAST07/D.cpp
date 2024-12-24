#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - 書き換え
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_d



int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<string> T = {"axa", "ixi", "uxu", "exe", "oxo"};
    for(int i = 0; i <= N - 3; i++) {
        if(find(T.begin(), T.end(), S.substr(i, 3)) != T.end()) {
            for(int j = 0; j < 3; j++) {
                S[i + j] = '.';
            }
        }
    }

    cout << S << endl;
}