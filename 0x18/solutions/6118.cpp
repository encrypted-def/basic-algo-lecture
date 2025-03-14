// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/1dae319e478f4366b1fde2d55a31f55f
#include <bits/stdc++.h>
using namespace std;

const int MX = 20'000;

vector<int> adj[MX + 2];
int dist[MX + 2], mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  int n, m; cin >> n >> m;

  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  dist[1] = 0;

  // bfs
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      mx = max(dist[nxt], mx);
      q.push(nxt);
    }
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(dist[i] == mx) {
      if(!cnt) cout << i << ' ';
      cnt++;
    }
  }
  cout << mx << ' ' << cnt;
}
/*
BFS를 적용합니다.
dist 배열은 -1로 초기화해서 방문 배열의 역할도 수행합니다.

모든 노드를 순회한 뒤 dist 배열을 확인하며
가장 거리가 먼 헛간 번호와 그 거리,
동일 거리에 있는 헛간 수를 출력합니다.
*/