#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Peaceful Teams
//    https://atcoder.jp/contests/abc310/tasks/abc310_d



int main() {
    int N, T, M;
    cin >> N >> T >> M;

    vector<int> ng(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        ng[A] |= 1 << B;
        ng[B] |= 1 << A;
    }

    vector<int> team;
    int ans = 0;
    auto f = [&](auto f, int now) -> void {
        if((int)team.size() > T) return;
        if(now == N) {
            if((int)team.size() == T) ans++;
            return;
        }

        for(int i = 0; i < (int)team.size(); i++) {
            if(team[i] & ng[now]) continue;
            team[i] ^= 1 << now;
            f(f, now + 1);
            team[i] ^= 1 << now;
        }

        if((int)team.size() < T) {
            team.push_back(1 << now);
            f(f, now + 1);
            team.pop_back();
        }
    };

    f(f, 0);
    cout << ans << endl;
}