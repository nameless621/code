#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Online games
//    https://atcoder.jp/contests/abc221/tasks/abc221_d



int main() {
    int N;
    cin >> N;

    map<int, int> M;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        M[A]++;
        M[A + B]--;
    }

    vector<long long> count(N + 1);
    int now = 0, pre = 0;
    for(auto[key, value] : M) {
        count[now] += key - pre;
        pre = key;
        now += value;
    }

    for(int i = 1; i <= N; i++) {
        cout << count[i] << " ";
    }
    cout << endl;
}