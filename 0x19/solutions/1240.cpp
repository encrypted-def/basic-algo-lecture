// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/dc926ebf7eb54c308dea376b240e0591
#include <bits/stdc++.h>
using namespace std;

const int MXN = 1010;
vector<pair<int, int>> adj[MXN];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, u, v, d;
  cin >> N >> M;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v >> d;
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
  }

  while (M--) {
    cin >> u >> v;
    queue<pair<int, int>> q;
    vector<bool> vis(N + 1);
    q.push({u, 0});
    vis[u] = true;
    while (!q.empty()) {
      auto [cur, dist] = q.front();
      q.pop();
      if (cur == v) {
        cout << dist << '\n';
        break;
      }
      for (auto [nxt, nxtDist] : adj[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        q.push({nxt, dist + nxtDist});
      }
    }
  }
}
/*
트리 구조여서 간선의 수는 N-1이니 bfs 한 번의 시간복잡도는 O(N)입니다. 
NM = 1,000,000이기 때문에 각 쿼리에 대해서 BFS 또는 DFS를 수행해도 O(NM)으로 무방합니다.
N <= 1000이고 M <= 5,000,000과 같이 M이 훨씬 더 컸다면 미리 bfs를 N번 돌려 모든 N^2개의 거리를
O(N^2)에 다 계산해 별도의 테이블에 저장해둔 후 답을 바로바로 출력하는 O(N^2+M) 풀이도 가능합니다.
만약 간선에 가중치가 있었다면 트리dp를 이용해 O(N^2+M)에 해결할 수 있습니다.
*/
