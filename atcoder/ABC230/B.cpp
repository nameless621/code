#include <bits/stdc++.h>
using namespace std;


//    B - Triple Metre
//    https://atcoder.jp/contests/abc230/tasks/abc230_b



int main() {
    string S;
    cin >> S;

    string T = "oxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxxoxx";
    bool ok = false;
    for(int i = 0; i < (int)T.size(); i++) {
        for(int j = 1; i + j <= (int)T.size(); j++) {
            if(T.substr(i, j) == S) {
                ok = true;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}