// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/781f212c4748490487a3071dad460e4f
#include <bits/stdc++.h>
using namespace std;

const int mn = 2e5+5, md = 2e9;
int n, m, s, e, d[mn];
bool pass[mn];
vector<pair<int, int>> adj[mn];
priority_queue<pair<int, int>> pq;

int dijk(int st, int en){
  fill(d, d+n+1, md);
  d[st] = 0;
  pq.push({0, st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    int w = -cur.first, u = cur.second;
    if(w != d[u]) continue;
    for(auto nxt : adj[u]){
      int v = nxt.first, nw = nxt.second;
      if(d[v] <= nw+w || pass[v]) continue;
      d[v] = nw+w;
      pq.push({-d[v], v});
    }
  }
  return d[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  cin >> s >> e;
  int d1 = dijk(e, s);
  int cur = s, dist = 0;
  while(cur != e){
    sort(adj[cur].begin(), adj[cur].end());
    for(auto nxt : adj[cur]){
      int v = nxt.first, w = nxt.second;
      if(dist + w + d[v] != d1) continue;
      dist += w;
      cur = v;
      if(cur != e) pass[cur] = true;
      break;
    }
  }
  int d2 = dijk(e, s);
  cout << d1+d2;
}

/*
첫 번째 다익스트라를 e에서 s로 돌리면, 각 정점들에서 e까지의 거리가 d에 저장됩니다.
s에서부터 시작하는 cur은 사전순으로 가장 앞서는 경로에 있는 다음 정점을 찾기 위해,
s에서 cur까지의 거리 + cur에서 nxt로의 가중치 + nxt에서 e까지의 거리 == 최단거리
를 만족하는 가장 낮은 번호의 정점을 선택합니다.
*/
