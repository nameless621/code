#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Full House
//    https://atcoder.jp/contests/abc263/tasks/abc263_a



int main() {
    vector<int> card(14);
    for(int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        card[num]++;
    }

    bool f1 = false, f2 = false;
    for(int i = 0; i < 14; i++) {
        if(card[i] == 2) f1 = true;
        if(card[i] == 3) f2 = true;
    }

    cout << (f1 && f2 ? "Yes" : "No") << endl;
}