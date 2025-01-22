#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Split?
//    https://atcoder.jp/contests/abc267/tasks/abc267_b



int main() {
    string S;
    cin >> S;

    if(S[0] == '1') {
        cout << "No" << endl;
        return 0;
    }

    vector<int> pin(7);
    if(S[6] == '1') pin[0]++;
    if(S[3] == '1') pin[1]++;
    if(S[1] == '1') pin[2]++;
    if(S[7] == '1') pin[2]++;
    if(S[4] == '1') pin[3]++;
    if(S[2] == '1') pin[4]++;
    if(S[8] == '1') pin[4]++;
    if(S[5] == '1') pin[5]++;
    if(S[9] == '1') pin[6]++;

    bool ok = false;
    for(int i = 0; i < 5; i++) {
        if(!pin[i]) continue;
        for(int j = i+2; j < 7; j++) {
            if(!pin[j]) continue;
            bool flag = true;
            for(int k = i+1; k < j; k++) {
                if(pin[k]) flag = false;
            }
            if(flag) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}