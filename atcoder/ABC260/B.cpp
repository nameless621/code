#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Better Students Are Needed!
//    https://atcoder.jp/contests/abc260/tasks/abc260_b



bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
    if (left.first == right.first) {
        return left.second < right.second;
    } else {
        return right.first < left.first;
    }
}

void func(vector<pair<int, int>> P, vector<bool>& ok, int cnt) {
    sort(P.begin(), P.end(), desc_asc);
    for(int i = 0; i < cnt; i++) {
        ok[P[i].second] = true;
    }
}

int main() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    vector<bool> ok(N);
    vector<pair<int, int>> P;
    for(int i = 0; i < N; i++) {
        P.emplace_back(A[i], i);
    }
    func(P, ok, X);

    P.clear();
    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        P.emplace_back(B[i], i);
    }
    func(P, ok, Y);

    P.clear();
    for(int i = 0; i < N; i++) {
        if(ok[i]) continue;
        P.emplace_back(A[i] + B[i], i);
    }
    func(P, ok, Z);

    for(int i = 0; i < N; i++) {
        if(ok[i]) cout << i + 1 << endl;
    }
}
