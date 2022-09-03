// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/3152615450164f11968c6f80dc779569
#include <bits/stdc++.h>
using namespace std;

const int MXN = 510;
vector<int> adj[MXN];
bool vis[MXN], isTree;
int n, m, u, v, tc, trees;
void dfs(int cur, int prev) {
  for (int nxt : adj[cur]) {
    if (nxt == prev)
      continue;
    if (vis[nxt]) {
      isTree = false;
      continue;
    }
    vis[nxt] = true;
    dfs(nxt, cur);
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    cin >> n >> m;
    if (!n && !m) break;

    fill(vis, vis + n + 1, 0);
    for (int i = 1; i <= n; i++)
      adj[i].clear();
    trees = 0;

    while (m--) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      vis[i] = true;
      isTree = true;
      dfs(i, -1);
      trees += isTree;
    }
    cout << "Case " << ++tc << ": ";
    if (!trees)
      cout << "No trees." << '\n';
    else if (trees == 1)
      cout << "There is one tree." << '\n';
    else
      cout << "A forest of " << trees << " trees." << '\n';
  }
}