// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2d3bd0eded28464b9abeb28f46d1f332
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int n, m;
int d[802];
vector<pair<int,int>> adj[802];

// st에서 en으로 가는 최단거리
ll solve(int st, int en){
  priority_queue< pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>> > pq;

  fill(d, d + n + 1, INF);
  d[st] = 0;
  pq.push({d[st], st});

  while(!pq.empty()){
    int u, v, w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      dw += w;
      if(dw < d[v]) {
        d[v] = dw;
        pq.push({dw, v});
      }
    }
  }
  return d[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int a, b, c;
  while(m--){
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  int e1, e2;
  cin >> e1 >> e2;
  ll ans1 = solve(1, e1) + solve(e1, e2) + solve(e2, n);
  ll ans2 = solve(1, e2) + solve(e2, e1) + solve(e1, n);
  ll ans = min(ans1, ans2);
  if(ans >= INF) ans = -1;
  cout << ans;
}
