#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    F - 不完全順列
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_f



int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> P(N);
    set<int> st;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') P[i] = i + 1;
        else st.insert(i + 1);
    }

    if((int)st.size() == 1) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        if(P[i] != 0) continue;
        auto itr = prev(st.end());
        if(*itr == i + 1) itr--;
        P[i] = *itr;
        st.erase(itr);
    }

    for(int i = 0; i < N; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
}