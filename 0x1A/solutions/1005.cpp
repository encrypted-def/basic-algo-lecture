// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ddd8214a903148c381289d51e1027039
#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, k; cin >> n >> k;
  vector<int> adj[n + 2];
  int cost[n + 2] = {};
  int tot[n + 2] = {};
  int ind[n + 2] = {};

  for(int i = 1; i <= n; i++)
    cin >> cost[i];

  while(k--) {
    int u, v;
    cin >> u >> v;
    ind[v]++;
    adj[u].push_back(v);
  }

  int w; cin >> w;
  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(!ind[i]) q.push(i);
  
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      tot[nxt] = max(tot[nxt], cost[cur] + tot[cur]);
      ind[nxt]--;
      if(!ind[nxt]) q.push(nxt);
    }
  }
  return tot[w] + cost[w];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--)
    cout << solve() << '\n';
}