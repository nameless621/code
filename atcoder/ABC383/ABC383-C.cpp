#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rrep(i, s, n) for (int i = (s); i >= (int)(n); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define uni(x) x.erase(unique(all(x)), x.end())
#define acc(x) accumulate(all(x), 0ll)
#define ins(A, B) A.insert(A.end(), B.begin(), B.end())
#define per(x) next_permutation(all(x))
#define sz(x) (int)(x).size()
#define popcnt(x) ll(__popcount(uint64_t(x)))
#define Mdist(x1, x2, y1, y2) abs(x1 - x2) + abs(y1 - y2)
#define Edist(x, y) (x) * (x) + (y) * (y)
#define pb push_back
#define eb emplace_back
#define em emplace
#define fi first
#define se second
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define print(...) cout << __VA_ARGS__ << "\n"
#define fix(x) cout << fixed << setprecision(12) << x << "\n"
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tiiii = tuple<int, int, int, int>;
using tlll = tuple<long long, long long, long long>;
using ll = long long;
using ull = unsigned long long;
using mint = modint998244353;
//using mint = modint1000000007;
template<typename T> using pq = priority_queue<T>;
template<typename T> using mpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
void yn(bool flag) { cout << (flag ? "Yes" : "No") << endl; }
bool rc(int i, int j, int h, int w) { return (i<0||i>=h||j<0||j>=w); }
bool kaibun(string s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
ll c2(ll n) { return n * (n-1) / 2; }
ll c3(ll n) { return n * (n-1) * (n-2) / 6; }
ll ceil(ll x, ll y) { return (x+y-1)/y; }


//    C - Humidifier 3
//    https://atcoder.jp/contests/abc383/tasks/abc383_c
//
//
//    加湿器が置かれた各マスからBFSする。おそらく工夫せずにやるとWA or TLEする。


int main() {
    int h, w, d; cin >> h >> w >> d;
    vs s(h);
    rep(i,h) cin >> s[i];

    vvi g(h, vi(w, -1));
    auto bfs = [&](int x, int y) {
        g[x][y] = d;
        queue<pii> q;
        q.em(x, y);
        while(q.size()) {
            auto[i,j] = q.front(); q.pop();
            if(g[i][j] == 0) continue;
            rep(k,4) {
                int a = i + dx[k];
                int b = j + dy[k];
                //マスの範囲外、床ではないマス、遷移先の移動回数が現在の移動回数 - 1以上であれば探索しない
                if(rc(a,b,h,w) || s[a][b] != '.' || g[a][b] >= g[i][j]-1) continue;
                g[a][b] = g[i][j] - 1;
                q.em(a,b);
            }
        }
    };

    //加湿器を見つけてBFSをする
    rep(i,h) rep(j,w) if(s[i][j] == 'H') {
        bfs(i,j);
    }

    int ans = 0;
    rep(i,h) rep(j,w) if(g[i][j] != -1) ans++;
    print(ans);
}
