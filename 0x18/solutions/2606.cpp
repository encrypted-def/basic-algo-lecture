// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/ed2204bdfebe40f3a2acae2a8b36d759
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> adj[105];
bool vis[105];
int cnt = 0;

void dfs(int u) {
  vis[u] = true;
  cnt++;
  for(auto& v : adj[u]) {
    if(vis[v]) continue;
    dfs(v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int m;
  cin >> m;
  while(m--) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  cout << cnt-1;
}
