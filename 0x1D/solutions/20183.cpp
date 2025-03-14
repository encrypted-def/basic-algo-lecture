// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/70a654102a304d8faa01b9e6866f8e66
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NMX = 100'000;
const int MMX = 500'000;

vector<pair<ll, int>> adj[MMX + 2]; // adj[cur] = {cost, nxt}
ll dist[NMX + 2];

ll lo = 1, hi;
int n, m, st, en; ll c;

bool solve(ll lim) {
  priority_queue < pair<ll, int>,
      vector<pair<ll, int>>,
      greater<pair<ll, int>> > pq;

  memset(dist, 0x3f, sizeof(dist));

  dist[st] = 0;
  pq.push({0, st});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(dist[cur] != co) continue;
    for(auto [d, nxt] : adj[cur]) {
      if(d > lim) continue;
      d += co;
      if(dist[nxt] <= d) continue;
      dist[nxt] = d;
      pq.push({d, nxt});
    }
  }

  if(dist[en] > c) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> st >> en >> c;

  while(m--) {
    int u, v; ll cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
    hi = max(hi, cost);
  }

  while(lo < hi) {
    ll mid = (lo + hi) / 2;
    if(solve(mid)) hi = mid;
    else lo = mid + 1;
  }

  if(solve(lo)) cout << lo;
  else cout << -1;
}
/*
최대 요금의 최솟값을 찾는 매개변수 탐색을 수행합니다(56-60번째 줄).

다익스트라 알고리즘을 통해 최단거리를 찾으면서
간선 비용 상한보다 큰 비용의 간선은 사용하지 않도록 구현합니다(30번째 줄).

다익스트라 알고리즘을 수행한 후,
목적지의 최소 비용과 가진 돈 C를 비교해
성공, 실패를 구분합니다(38-39번째 줄).
*/