// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/8d181bd675584722a8beffeb4f4d5476
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 77'777'777'777;
const int MX = 100'000 + 2;

int n, m; ll dist[MX];
vector<pair<int, int>> adj[MX];

priority_queue< pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>> > pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(dist, dist + MX, INF);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back({i, v});
    adj[v].push_back({i, u});
  }

  const int MOD = m;
  pq.push({0, 1});
  dist[1] = 0;
  while(!pq.empty()) {
    auto [cd, cur] = pq.top(); pq.pop();
    if(dist[cur] != cd) continue;
    for(auto [rmd, nxt] : adj[cur]) {
      ll nd = (rmd - cd) % MOD;
      if (nd < 0) nd += MOD;
      nd += cd + 1;
      if(nd >= dist[nxt]) continue;
      dist[nxt] = nd;
      pq.push({nd, nxt});
    }
  }
  cout << dist[n];
}
/*
dist를 초기화할 값을 결정하기 위해 가장 긴 최단거리를 고려하자.
최악의 경우 70만 분씩 걸려 10만 개 정점을 건너게 될 수도 있으므로,
dist를 초기화할 때 활용하는 INF 값을 77'777'777'777으로 설정하였다(8번째 줄).
그리고 이에 따라 dist는 long long으로 선언하였다.

정점 1에서 cur까지 가는 확정된 최단 거리를 cd라 하자.
횡단보도가 켜지는 때가 rmd인 정점 nxt로 건너갈 수 있게 되는
가장 빠른 시점을 구해야 한다.

기다려야 하는 최소 시간을 x라고 하자.
(cd + x) ≡ rmd (mod MOD)를 만족해야 한다.
x ≡ rmd - cd (mod MOD)이며,
x는 (rmd - cd) % MOD로 나머지를 구할 수 있다.
만약 이 값이 음수인 경우엔 MOD를 더하여 구할 수 있다(38-39번째 줄).

이 기다려야 하는 최소 시간 후에 출발하여 1분 후 정점 nxt에 도달할 수 있으므로,
정점 1에서 nxt로 가는 거리인 nd는 위에서 구한 x에 (cd + 1)을 더해 구할 수 있다.
위 풀이에서는 x를 nd에 저장했으므로, nd += cd + 1;로 구했다(40번째 줄).

만약 이렇게 구한 nd가 dist[nxt]보다 크거나 같다면 이 계산한 값을 무시하고,
nd가 정점 1에서 nxt로 가는 새로운 최단거리라면 우선순위 큐에 넣는다(41-43번째 줄).
이 과정을 우선순위 큐가 빌 때까지 반복하고, dist[n]을 출력한다.
*/