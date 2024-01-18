// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/7c66cf32b7fd47168685b68fa5f06e8b
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, m, st, en;
bool is_opt_path[10002];
int dist[502];

 //adj[cur], rev_adj[cur] = {cost, nxt, id};
vector<tuple<int, int, int>> adj[502];
vector<tuple<int, int, int>> rev_adj[502];

priority_queue< pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>> > pq;

queue<int> q;

void setup() {
  for (int i = 0; i < n; i++) {
    adj[i].clear(); rev_adj[i].clear();
  }
  fill(is_opt_path, is_opt_path + m, 0);

  cin >> st >> en;
  for (int id = 0; id < m; id++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v, id});
    rev_adj[v].push_back({cost, u, id});
  }
}

void solve() {
  fill(dist, dist + n, INF);
  dist[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt, id] : adj[cur]) {
      if (is_opt_path[id]) continue;
      dco += co;
      if (dist[nxt] <= dco) continue;
      dist[nxt] = dco;
      pq.push({dco, nxt});
    }
  }
}

void trace() {
  q.push(en);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (auto [dco, prv, id] : rev_adj[cur]) {
      if (is_opt_path[id]) continue;
      int d = dist[cur] - dco;
      if (dist[prv] != d) continue;
      q.push(prv);
      is_opt_path[id] = 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (n != 0 || m != 0) {
    setup();
    solve();
    trace();
    solve();

    if (dist[en] == INF) dist[en] = -1;
    cout << dist[en] << '\n';
    cin >> n >> m;
  }
}
/*
adj와 rev_adj는 주어진 간선과 그에 대한 역방향 간선을 저장
간선 정보는 간선 비용과 다음 노드, 그리고 간선의 고유번호를 저장
is_opt_path는 간선의 고유번호를 받아 최단 경로에 활용된 간선인지 bool 값을 반환

main 함수(69-84번째 줄)
- setup 함수 호출하고 solve 함수 호출
- trace 함수를 통해 최단 경로에 활용되는 간선 기록
- solve 함수로 거의 최단 경로를 구함
- 거의 최단 경로가 없는 경우 -1을 반환. 그외엔 거의 최단 경로를 반환(80-82번째 줄)

setup 함수(23-36번째 줄)
- 간선과 역방향 간선 정보 초기화(24-27번째 줄) 및 저장(30-35번째 줄)
- 최단 경로 기록 배열 초기화(27번째 줄)

solve 함수(38-53번째 줄)
- 다익스트라 알고리즘 구현
- 최단 경로로 활용된 간선이라면 해당 경로는 사용하지 않음(46번째 줄)
  첫 번째 solve 시에는 최단 경로로 활용된 간선을 기록하지 않기 때문에
  이에 무관하게 다익스트라 알고리즘이 동작함

trace 함수(55-67번째 줄)
- 도착 지점에서부터 최단 경로를 BFS로 역추적함
- cur 정점에서 역방향 간선을 확인하며 prv 정점의 거리를 확인함
- 최단 경로 상 간선은 dist[cur]에서 간선 비용인 dco를 빼면 dist[prv]가 되어야 함
  이를 만족하는 정점인 prv는 큐에 넣고 BFS를 수행하며,
  간선은 최단 경로 상 간선으로 기록(61-64번째 줄)
- 중복되는 확인을 막기 위해 최단 경로에 활용된 간선인 경우에 확인 작업을 건너뜀(60번째 줄)
*/