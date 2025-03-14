// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/5749cd611d144c23acee996db02f173e
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, st, en;
int d[1002];
vector<pair<int,int>> adj[1002];

int solve(){
  priority_queue< pair<int, int>,
                  vector<pair<int, int>>,
                  greater<pair<int, int>> > pq;
  d[st] = 0;
  pq.push({0, st});
  while(!pq.empty()){
    int u, v, w, dw;
    tie(w, u) = pq.top(); pq.pop();
    if(d[u] != w) continue;
    for(auto nxt : adj[u]){
      tie(dw, v) = nxt;
      dw += w;
      if(d[v] <= dw) continue;
      d[v] = dw;
      pq.push({dw, v});
    }
  }
  return d[en];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(d, d + n + 1, INF);

  int u, v, w;
  while(m--){
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  cin >> st >> en;
  cout << solve();
}