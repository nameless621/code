#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - 最速正解者
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_c



int main() {
    int N;
    cin >> N;

    vector<int> ans(6, -1);
    for(int i = 0; i < N; i++) {
        char P;
        string V;
        cin >> P >> V;
        if(V == "AC" && ans[P - 'A'] == -1) {
            ans[P - 'A'] = i + 1;
        }
    }

    for(int num : ans) cout << num << endl;
}