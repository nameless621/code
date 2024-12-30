#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Strange Balls
//    https://atcoder.jp/contests/abc240/tasks/abc240_d



int main() {
    int N;
    cin >> N;

    int count = 0;
    stack<pair<int, int>> st;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        count++;
        if(st.empty() || st.top().first != a) {
            st.emplace(a, 1);
        }
        else {
            st.top().second++;
            if(st.top().first == st.top().second) {
                count -= st.top().second;
                st.pop();
            }
        }
        cout << count << endl;
    }
}