#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<int> vi;
typedef vector<unordered_set<int>> graph;

struct UnionFind {
private:
  int sets;
  vi par, sz;
public:
  UnionFind(int N) : sets(N) { par.assign(N, -1); sz.assign(N, 1); }
  int root(int i) { return (par[i] < 0) ? i : (par[i] = root(par[i])); }  
  void merge(int i, int j) {
    i = root(i); j = root(j);
    if (i == j) return;
    --sets;
    if (sz[i] < sz[j]) swap(i, j);
    par[j] = i; 
    sz[i] += sz[j];
  }
  int size(int i) { return sz[root(i)]; }
  bool same(int i, int j) { return root(i) == root(j); }
  int size() { return sets; }
};

struct TarjanSCC {
private:
  graph g;
  int i;
  vi ind, low, stk;
  vector<bool> on;
  void dfs(int u, vector<unordered_set<int>>& sccs) {
    ind[u] = low[u] = i++;
    stk.pb(u);
    on[u] = true;
    
    for (int v : g[u]) {
      if (ind[v] == -1) {
        dfs(v, sccs);
        low[u] = min(low[u], low[v]);
      } else if (on[v]) {
        low[u] = min(low[u], ind[v]);
      }
    }

    if (low[u] == ind[u]) {
      sccs.pb(unordered_set<int>());
      int v = -1;
      while (u != v) {
        v = stk.back(); stk.pop_back();
        on[v] = false;
        sccs.back().insert(v);
      }
    }
  }    
public:
  TarjanSCC(graph& gr) { g = gr; }
  void find_components(vector<unordered_set<int>>& sccs) {
    i = 0;
    int n = g.size();
    ind.assign(n, -1); low.assign(n, 0); on.assign(n, 0);
    for (int u = 0; u < n; ++u) {
      if (ind[u] == -1) dfs(u, sccs);
    }
  }
};

int main() {
  int n, m, s1, s2;
  int tt; cin >> tt; for (int t = 0; t < tt; ++t) {
    cin >> n >> m;
    graph impl(n);
    for (int i = 0; i < m; ++i) {
      cin >> s1 >> s2;
      impl[--s1].insert(--s2);
    }

    TarjanSCC tar(impl);
    vector<unordered_set<int>> sccs;
    unordered_map<int, int> scc;
    tar.find_components(sccs);
    if (sccs.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < (int)sccs.size(); ++i) 
      for (int j : sccs[i]) scc[j] = i;

    // g is condensation of implications
    graph g(sccs.size());
    vi root(g.size(), 1);
    vi counted(g.size());
    UnionFind uf(g.size());
    int count = 0;
    for (int i = 0; i < (int)sccs.size(); ++i) {
      for (int u : sccs[i]) {
        for (int v : impl[u]) {
          int j = scc[v];
          if (j != i) {
            g[i].insert(j);
            uf.merge(i, j);
          }
          root[j] = 0;
        }
      }
    }
    int l = 0, r = 0;
    for (int u = 0; u < (int)g.size(); ++u) {
      if (g[u].size() == 0) ++l;
      else if (root[u]) {
        if (counted[uf.root(u)]) ++r;
        else counted[uf.root(u)] = 1;
      } 
    }
    cout << r + l << endl;
  }
}
