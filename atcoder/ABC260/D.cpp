#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Draw Your Cards
//    https://atcoder.jp/contests/abc260/tasks/abc260_d



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    set<int> s;
    vector<int> ans(N, -1);
    vector<vector<int>> f(N);
    for(int i = 0; i < N; i++) {
        if(s.empty()) {
            if(K == 1) ans[P[i]] = i + 1;
            else s.insert(P[i]);
        }
        else {
            auto itr = s.lower_bound(P[i]);
            if(itr != s.end()) {
                if((int)f[*itr].size() == K - 2) {
                    for(int idx : f[*itr]) {
                        ans[idx] = i + 1;
                    }
                    ans[*itr] = i + 1;
                    ans[P[i]] = i + 1;
                    s.erase(itr);
                }
                else {
                    swap(f[P[i]], f[*itr]);
                    f[P[i]].push_back(*itr);
                    s.erase(itr);
                    s.insert(P[i]);
                }
            }
            else {
                s.insert(P[i]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
