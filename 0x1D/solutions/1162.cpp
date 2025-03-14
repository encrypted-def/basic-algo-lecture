// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/0abf612fc1d544f496f3b7952a8d18fa
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int KMX = 20;
const int NMX = 10'000;

int n, m, k;
ll dist[KMX + 2][NMX + 2];
vector<tuple<ll, int, int>> adj[NMX + 2]; // adj[u] = {cost, dk, v}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, 0x3f, sizeof(dist));

  cin >> n >> m >> k;
  while(m--) {
    int u, v; ll cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, 0, v});
    adj[v].push_back({cost, 0, u});
    adj[u].push_back({0, 1, v});
    adj[v].push_back({0, 1, u});
  }

  priority_queue< tuple<ll, int, int>,
      vector<tuple<ll, int, int>>, 
      greater<tuple<ll, int, int>> > pq; // {cost, ck, v}

  for(int i = 0; i <= k; i++)
    dist[i][1] = 0;
  pq.push({0, 0, 1});

  while(!pq.empty()) {
    auto [cc, ck, cur] = pq.top(); pq.pop();
    if(dist[ck][cur] != cc) continue;
    for(auto [dc, dk, nxt] : adj[cur]) {
      dc += cc;
      dk += ck;
      if(dc >= dist[dk][nxt]) continue;
      if(dk > k) continue;
      dist[dk][nxt] = dc;
      pq.push({dc, dk, nxt});
    }
  }

  ll ans = 0x3f3f3f3f3f3f3f;
  for(int i = 0; i <= k; i++)
    ans = min(ans, dist[i][n]);
  cout << ans;
}
/*
도시 수가 10,000이고, 비용이 백만 이하기 때문에 int형 변수 범위를 벗어날 수 있으므로
최단 거리는 long long 변수로 선언합니다.

최단 거리 테이블을 포장 횟수에 따라 구분해 기록합니다.
이를 위해 간선 정보에는 포장 횟수 증가량(dk)을,
힙에는 현재까지 포장한 횟수(ck)를 기록합니다.

간선의 경우 포장을 수행하면 비용이 0이 되기 때문에
비용은 0, 포장 횟수 증가량(dk)은 1인 간선이라 기록합니다(27-28번째 줄).

이후 다익스트라 알고리즘을 활용해 최단 거리 테이블을 채웁니다.
힙에는 현재까지 포장한 횟수(ck)가 기록되기 때문에, 포장횟수 제한 값(k)을 초과하는 경우
해당 간선 정보를 무시하도록 구현합니다(46번째 줄).
*/