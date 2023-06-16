// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/b451e35539534204b5962ebf79a9b6d4
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, m, k, st, en;
int dist[1002][1002];
int inc[30002];

priority_queue< tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

vector<pair<int, int>> adj[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i <= 1000; i++)
    fill(dist[i], dist[i] + 1001, INF);

  cin >> n >> m >> k;
  cin >> st >> en;

  while (m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }

  for (int i = 1; i <= k; i++)
    cin >> inc[i];

  dist[0][st] = 0;
  // pq : {cost, nop, cur}, nop: no of paths pass through
  pq.push({0, 0, st});
  while (!pq.empty()) {
    auto [co, nop, cur] = pq.top(); pq.pop();
    if (dist[nop][cur] != co) continue;
    if (nop == n) continue;
    for (auto [dco, nxt] : adj[cur]) {
      dco += co;
      if (dco >= dist[nop + 1][nxt]) continue;
      dist[nop + 1][nxt] = dco;
      pq.push({dco, nop + 1, nxt});
    }
  }

  for (int i = 0; i <= k; i++) {
    int ans = INF;
    for (int nop = 0; nop <= n; nop++) {
      dist[nop][en] += inc[i]*nop;
      ans = min(ans, dist[nop][en]);
    }
    cout << ans << '\n';
  }
}
/*
통과하는 도로의 총 개수를 상태로써 기록한다.
- 우선순위 큐에는 {비용, 방문한 정점 수, 현재 정점 번호}를 튜플로 기록한다.
- 최단 경로 배열 dist는 방문한 정점 수와 정점 번호로 인덱싱된다.
- 어떤 최단경로도 (N - 1)개 이상의 정점을 방문하진 않는다:
  이 경우 모든 정점을 방문하게 되며, 이보다 더 많은 정점을 방문하는 경우 최단 경로가 될 수 없다.

i번째에 인상되는 세금양은 지나온 경로 수와 증가하는 세금양을 곱한 값이 된다(57번째 줄).
이를 dist[nop][en]에 더하여 증가된 세금을 산정하고,
반복문을 통해 인상된 세금 중 최소 통행료를 갱신한 뒤 답으로 출력한다(54-61번째 for문).
*/