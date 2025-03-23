#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Yet Another Sigma Problem
//    https://atcoder.jp/contests/abc353/tasks/abc353_e



struct Trie {
    struct Node {
        unordered_map<char,int> to;
        int cnt;
        Node(): cnt(0) {}
    };
    vector<Node> d;
    Trie(): d(1) {}
    void add(const string& s) {
        int v = 0;
        for (char c : s) {
            if (!d[v].to.count(c)) {
                d[v].to[c] = d.size();
                d.push_back(Node());
            }
        v = d[v].to[c];
        }
        d[v].cnt++;
    }
  
    long long ans;
    int dfs(int v) {
        int res = d[v].cnt;
        for (auto p : d[v].to) {
            res += dfs(p.second);
        }
        if (v) ans += res*(long long)(res-1)/2;
        return res;
    }
    long long solve() {
        ans = 0;
        dfs(0);
        return ans;
    }
};

int main() {
    int N;
    cin >> N;

    Trie tr;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        tr.add(S);
    }

    cout << tr.solve() << endl;
}