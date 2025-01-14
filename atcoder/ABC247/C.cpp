#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - 1 2 1 3 1 2 1 
//    https://atcoder.jp/contests/abc247/tasks/abc247_c



vector<int> f(int n) {
    if(n == 1) return {1};
    vector<int> res = f(n - 1);
    res.push_back(n);
    int len = res.size();
    for(int i = 0; i < len - 1; i++) {
        res.push_back(res[i]);
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    for(int num : f(N)) {
        cout << num << " ";
    }
    cout << endl;
}