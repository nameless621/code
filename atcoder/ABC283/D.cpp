#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Scope 
//    https://atcoder.jp/contests/abc283/tasks/abc283_d



int main() {
    string S;
    cin >> S;

    int N = S.size();
    bool ok = true;
    vector<bool> ball(26);
    vector<vector<char>> box(1);
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') {
            box.push_back(vector<char>());
        }
        else if(S[i] == ')') {
            if(box.empty()) continue;
            for(char c : box.back()) {
                ball[c - 'a'] = false;
            }
            box.pop_back();
        }
        else {
            box.back().push_back(S[i]);
            if(ball[S[i] - 'a']) ok = false;
            ball[S[i] - 'a'] = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}