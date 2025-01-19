#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Addition and Multiplication 2
//    https://atcoder.jp/contests/abc254/tasks/abc257_e



int main() {
    int N;
    cin >> N;

    vector<int> C(9);
    int idx = -1, cost = N + 1;
    for(int i = 0; i < 9; i++) {
        cin >> C[i];
        if(cost >= C[i]) {
            idx = i;
            cost = C[i];
        }
    }

    int len = N / cost;
    vector<char> res(len, '0' + idx + 1);
    for(int i = 0; i < len; i++) {
        for(int j = 8; j >= 0; j--) {
            int temp = (len - i - 1) * cost + C[j];
            if(temp <= N) {
                res[i] = '0' + j + 1;
                N -= C[j];
                break;
            }
        }
    }

    for(char num : res) cout << num;
    cout << endl;
}