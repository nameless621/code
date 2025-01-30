#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Cards Query Problem
//    https://atcoder.jp/contests/abc298/tasks/abc298_c



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<set<int>> card(2e5 + 1);
    vector<multiset<int>> box(2e5 + 1);
    while(Q--) {
        int T, i, j;
        cin >> T;
        if(T == 1) {
            cin >> i >> j;
            box[j].insert(i);
            card[i].insert(j);
        }
        if(T == 2) {
            cin >> i;
            for(int num : box[i]) cout << num << " ";
            cout << endl;
        }
        if(T == 3) {
            cin >> i;
            for(int num : card[i]) cout << num << " ";
            cout << endl;
        }
    }
}