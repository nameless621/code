#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Karuta
//    https://atcoder.jp/contests/abc287/tasks/abc287_e



struct Trie {
  struct Node {
    unordered_map<char,int> to;
    int cnt;
    int subCnt;
    Node(): cnt(0), subCnt(0) {}
  };
  vector<Node> d;
  Trie(){ d.push_back(Node()); }
  
  void add(const string &s){
    int v=0;
    d[v].subCnt++;
    for(char c:s){
      if(!d[v].to.count(c)){
        d[v].to[c]=d.size();
        d.push_back(Node());
      }
      v=d[v].to[c];
      d[v].subCnt++;
    }
    d[v].cnt++;
  }

  int matchPrefix(const string &t){
    int v=0,len=0;
    for(char c:t){
      if(!d[v].to.count(c))break;
      v=d[v].to[c]; 
      len++;
    }
    return len;
  }
  
  int matchPrefixExcept(const string &t){
    int v=0, len=0;
    for(char c:t){
      auto it=d[v].to.find(c);
      if(it==d[v].to.end())break;
      int nx=it->second;
      if(d[nx].subCnt==1){
        break;
      }
      v=nx;
      len++;
    }
    return len;
  }
};


int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    Trie tr;
    for(int i = 0; i < N; i++) {
        cin >> S[i];
        tr.add(S[i]);
    }

    for(int i = 0; i < N; i++) {
        cout << tr.matchPrefixExcept(S[i]) << endl;
    }
}