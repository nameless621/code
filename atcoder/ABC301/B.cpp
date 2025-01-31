#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Fill the Gaps
//    https://atcoder.jp/contests/abc301/tasks/abc301_b



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> res = {A[0]};
    for(int i = 1; i < N; i++) {
        if(abs(res.back() - A[i]) != 1) {
            if(res.back() < A[i]) {
                int temp = res.back() + 1;
                while(abs(temp - A[i]) != 1) {
                    res.push_back(temp);
                    temp++;
                }
                res.push_back(temp);
            }
            else {
                int temp = res.back() - 1;
                while(abs(temp - A[i]) != 1) {
                    res.push_back(temp);
                    temp--;
                }
                res.push_back(temp);
            }
        }
        res.push_back(A[i]);
    }

    for(int num : res) cout << num << " ";
    cout << endl;
}