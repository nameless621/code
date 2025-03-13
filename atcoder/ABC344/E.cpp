#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Insert or Erase
//    https://atcoder.jp/contests/abc344/tasks/abc344_e



const int INF = 1001001001;
struct Node {
  int pre, nxt;
  Node(int pre=-1, int nxt=-1): pre(pre), nxt(nxt) {}
};
struct List {
  unordered_map<int,Node> nodes;
  int head, tail;
  List(): head(-INF), tail(INF) {
    nodes[head] = Node(-1,tail);
    nodes[tail] = Node(head,-1);
  }
  void erase(int x) {
    Node a = nodes[x];
    nodes[a.pre].nxt = a.nxt;
    nodes[a.nxt].pre = a.pre;
    nodes.erase(x);
  }
  void addR(int x, int y) {
    int z = nodes[x].nxt;
    nodes[x].nxt = y;
    nodes[z].pre = y;
    nodes[y] = Node(x,z);
  }
  void addL(int x, int y) {
    int z = nodes[x].pre;
    nodes[z].nxt = y;
    nodes[x].pre = y;
    nodes[y] = Node(z,x);
  }
  void print() {
    int i = nodes[head].nxt;
    while (i != tail) {
      cout << i << ' ';
      i = nodes[i].nxt;
    }
    cout << endl;
  }
  int size() const {
    return nodes.size()-2;
  }
  bool count(int x) const {
    return nodes.count(x) > 0;
  }
};

int main() {
    int N;
    cin >> N;

    List L;
    int now = L.head;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        L.addR(now, A);
        now = A;
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int op, x, y;
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            L.addR(x, y);
        }
        else {
            cin >> x;
            L.erase(x);
        }
    }

    L.print();
}