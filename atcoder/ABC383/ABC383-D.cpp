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


//    D - 9 Divisors
//    https://atcoder.jp/contests/abc383/tasks/abc383_d
//
//
//    整数Nの約数の個数は、素因数分解してそれぞれの(指数 + 1)を全て掛け合わせた数に等しい
//    約数がちょうど9個となるN以下の正整数の個数を求めたいので、相異なる素数p, qとして、p^2 * q^2 <= Nとなる数と、p^8 <= Nとなる数を数え上げればよい



//エラトステネスの篩で素数リスト生成
//入力されるNは最大で4 * 10^12と巨大だが、N以下となるp^2 * q^2もしくはp^8を計算したいので、√Nの範囲で列挙すれば十分
vector<ll> E(ll n) {
    vector<bool> isprime(n+1, true);
    vector<ll> prime;
    isprime[0] = isprime[1] = false;
    for (ll p = 2; p <= n; ++p) {
        if (!isprime[p]) continue;
        prime.push_back(p);
        for (ll q = p * 2; q <= n; q += p) isprime[q] = false;
    }
    return prime;
}


int main() {
    ll n; cin >> n;
    vl p = E(2e6);
    set<ll> s;
    //オーバーフロー防ぐため(p^2 <= n), (q^2 <= n), (p^2 * q <= n), (p^2 * q^2 <= n)で判定する
    rep(i,sz(p)) if(p[i] * p[i] <= n) reps(j,i+1,sz(p)) if(p[j] * p[j] <= n) {
        ll x = p[i] * p[i] * p[j];
        if(x > n) break;
        x *= p[j];
        if(x > n) break;
        s.insert(x);
    }

    //p^8の個数を数える。Nを超えた時点で探索を終了する
    rep(i,sz(p)) {
        bool ok = true;
        ll x = 1;
        rep(k,8) {
            x *= p[i];
            if(x > n) {
                ok = false;
                break;
            }
        }
        if(ok) s.insert(x);
        else break;
    }

    print(sz(s));
}
