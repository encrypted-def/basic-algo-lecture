// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/0e6ad8751a9748d7bd32b9115678b6f6
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
vector<pair<int,int>> adj[1002];

int solve(int st, int en){
  int d[1002];
  fill(d, d + n + 1, INF);
  priority_queue< pair<int,int>,
                  vector<pair<int,int>>,
                  greater<pair<int,int>> > pq;
  d[st] = 0;
  pq.push({0, st});
  while(!pq.empty()){
    int u, v, w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      if(dw + w < d[v]) {
        d[v] = dw + w;
        pq.push({d[v], v});
      }
    }
  }
  return d[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int en;
  cin >> n >> m >> en;

  int u, v, w;
  while(m--) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }

  int ans = 0;
  for(int st = 1; st <= n; st++)
    ans = max(ans, solve(st, en) + solve(en, st));
  cout << ans;
}