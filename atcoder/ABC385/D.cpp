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
#define Mdist(x1, y1, x2, y2) abs(x1 - x2) + abs(y1 - y2)
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




int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;

    map<ll, set<ll>> tate, yoko;
    rep(i,n) {
        int a, b; cin >> a >> b;
        tate[a].insert(b);
        yoko[b].insert(a);
    }

    int ans = 0;
    while(m--) {
        char d;
        ll c;
        cin >> d >> c;
        if(d == 'U') {
            auto &st = tate[x];
            auto itr = st.lower_bound(y);
            while(itr != st.end() && *itr <= y + c) {
                ans++;
                yoko[*itr].erase(x);
                itr = st.erase(itr);
            }
            y += c;
        }
        if(d == 'D') {
            auto &st = tate[x];
            auto itr = st.lower_bound(y-c);
            while(itr != st.end() && *itr <= y) {
                ans++;
                yoko[*itr].erase(x);
                itr = st.erase(itr);
            }
            y -= c;
        }
        if(d == 'R') {
            auto &st = yoko[y];
            auto itr = st.lower_bound(x);
            while(itr != st.end() && *itr <= x + c) {
                ans++;
                tate[*itr].erase(y);
                itr = st.erase(itr);
            }
            x += c;
        }
        if(d == 'L') {
            auto &st = yoko[y];
            auto itr = st.lower_bound(x-c);
            while(itr != st.end() && *itr <= x) {
                ans++;
                tate[*itr].erase(y);
                itr = st.erase(itr);
            }
            x -= c;
        }
    }

    cout << x << " " << y << " " << ans << endl;
}