#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Poem Online Judge
//    https://atcoder.jp/contests/abc251/tasks/abc251_c



int main() {
    int N;
    cin >> N;

    set<string> seen;
    vector<pair<int, int>> P;
    for(int i = 0; i < N; i++) {
        string S;
        int T;
        cin >> S >> T;
        if(seen.count(S)) continue;
        seen.insert(S);
        P.emplace_back(T, i + 1);
    }

    sort(P.begin(), P.end(), [&](const pair<int, int>& A, const pair<int, int>& B) {
        if(A.first == B.first) return A.second < B.second;
        else return B.first < A.first;
    });

    cout << P[0].second << endl;
}
