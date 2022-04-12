// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/f2ade30d63bf41ecb44dd0472a692337
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[550];
int dist[550];
int cnt;

void bfs() {
  queue<int> q;
  dist[1] = 0;
  q.push(1);

  while(!q.empty()) {
    auto u = q.front();
    // 친구와 친구의 친구는 거리가 각각 1,2인 노드들이다.
    if (1 <= dist[u] && dist[u] <= 2)
      cnt++;

    if(dist[u] > 2)
      break;

    q.pop();
    for(auto& v : adj[u]) {
      if(dist[v] >= 0) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  fill(dist,dist+n+1, -1);

  for(int i{}; i<m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs();
  cout << cnt;
}
