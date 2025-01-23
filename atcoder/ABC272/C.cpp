#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Max Even
//    https://atcoder.jp/contests/abc272/tasks/abc272_c



int main() {
    int N;
    cin >> N;
    vector<int> odd, even;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if(A & 1) odd.push_back(A);
        else even.push_back(A);
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int x = -1, y = -1;
    if((int)odd.size() > 1) x = odd[0] + odd[1];
    if((int)even.size() > 1) y = even[0] + even[1];

    cout << max(x, y) << endl;
}