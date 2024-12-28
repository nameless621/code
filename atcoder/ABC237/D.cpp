#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - LR insertion
//    https://atcoder.jp/contests/abc237/tasks/abc237_d



int main() {
    int N;
    string S;
    cin >> N >> S;

    deque<int> A;
    A.push_back(N);
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == 'L') A.push_back(i);
        else A.push_front(i);
    }

    for(int num : A) cout << num << " ";
    cout << endl;
}