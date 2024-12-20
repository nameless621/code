#include <bits/stdc++.h>
using namespace std;


//    A - AtCoder Quiz 3
//    https://atcoder.jp/contests/abc230/tasks/abc230_a



int main() {
    int N;
    cin >> N;
    if(42 <= N) N++;
    cout << "AGC" << string(3 - to_string(N).size(), '0') << N << endl;
}