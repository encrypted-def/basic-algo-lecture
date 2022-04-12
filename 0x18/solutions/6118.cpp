// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/fb3e594cf84a44c0a7185696459fb5df
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20'005];
int dist[20'005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  for(int i{}; i<m; ++i) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  //bfs를 통해 1번노드에서 가장 거리가 먼 곳 고르기
  fill(dist,dist+n+1,-1);
  queue<int> q;
  q.push(1);
  dist[1] = 0;

  while(!q.empty()) {
    auto u = q.front();
    q.pop();

    for(auto v : adj[u]) {
      if(dist[v] >= 0) continue;
      dist[v] = dist[u]+1;
      q.push(v);
    }
  }

  auto max_dist = *max_element(dist,dist+n+1);
  auto cnt = 0;
  for(int i{1}; i<=n; ++i)
    if(dist[i] == max_dist)
      cnt++;

  for(int i{1}; i<=n; ++i) {
    if(dist[i] == max_dist) {
      cout << i << ' ' << max_dist << ' ' << cnt;
      return 0;
    }
  }
}
