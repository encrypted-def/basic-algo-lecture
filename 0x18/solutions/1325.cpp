// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/7fcf2dccf277465db272d434f1f98b1a
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10'005];
bool vis[10'005];
int hack_cnt[10'005];

int dfs(int u) {
  int cnt = 1;
  vis[u] = true;
  for(auto v : adj[u]) {
    if(vis[v]) continue;
    cnt += dfs(v);
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  for(int i{}; i<m; ++i) {
    int u, v;
    cin >> v >> u;
    adj[u].push_back(v);
  }

  for(int i{1}; i<=n; ++i) {
    fill(vis,vis+n+1,false);
    hack_cnt[i] = dfs(i);
  }

  auto max_cnt = *max_element(hack_cnt,hack_cnt+n+1);

  for(int i{1}; i<=n; ++i)
    if(hack_cnt[i] == max_cnt)
      cout << i << ' ';
}
