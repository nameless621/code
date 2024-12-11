#include <bits/stdc++.h>
using namespace std;


//    A - Last Card
//    https://atcoder.jp/contests/abc227/tasks/abc227_a



int main() {
    int N, K, A;
    cin >> N >> K >> A;
    
    K--;
    while(K--) {
        if(A == N) A = 1;
        else A++;
    }
    

    cout << A << endl;
}