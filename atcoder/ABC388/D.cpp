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
#define popcnt(x) int(__popcount(uint64_t(x)))
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
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using tiii = tuple<int, int, int>;
using tiiii = tuple<int, int, int, int>;
using tlll = tuple<long long, long long, long long>;
using ll = long long;
using ull = unsigned long long;
using mint = modint998244353;
// using mint = modint1000000007;
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



using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b){ return std::min(a, b); }
S e(){ return INF; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    int n; cin >> n;
    vector<S> a(n);
    rep(i,n) cin >> a[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    int x = n - 1;
    rep(i,n-1) {
        int now = seg.get(i);
        if(now >= x) {
            seg.set(i, now - x);
            seg.apply(i+1, n, 1);
        }
        else {
            seg.apply(i+1, i+now+1, 1);
            seg.set(i, 0);
        }
        x--;
    }

    rep(i,n) cout << seg.get(i) << " ";
    cout << endl;
}