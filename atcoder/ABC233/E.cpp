#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Σ[k=0..10^100]floor(X／10^k)
//    https://atcoder.jp/contests/abc233/tasks/abc233_e



int main() {
    string X;
    cin >> X;

    vector<int> A;
    int sum = 0;
    for(int i = 0; i < (int)X.size(); i++) {
        sum += X[i] - '0';
        A.push_back(sum);
    }

    vector<int> result;
    while(!A.empty()) {
        int num = A.back();
        A.pop_back();
        result.push_back(num % 10);
        num /= 10;
        if((int)A.size() > 0) {
            A.back() += num;
        } 
        else if(num > 0) {
            result.push_back(num);
        }
    }

    reverse(result.begin(), result.end());
    for(int num : result) cout << num;
    cout << endl;
}