#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Playing Cards Validation
//    https://atcoder.jp/contests/abc277/tasks/abc277_b



int main() {
    int N;
    cin >> N;

    string c1 = "HDCS";
    string c2 = "A23456789TJQK";
    bool ok = true;
    set<string> st;

    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if(c1.find(S[0]) == string::npos) ok = false;
        if(c2.find(S[1]) == string::npos) ok = false;
        if(st.count(S)) ok = false;
        st.insert(S);
    }

    cout << (ok ? "Yes" : "No") << endl;
}