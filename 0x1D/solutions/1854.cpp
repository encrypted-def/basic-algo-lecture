// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/2e7aad928479422d845f500c2c77609b
#include <bits/stdc++.h>
using namespace std;

const int mn = 1e4+5;
int n, m, k;
vector<int> d[mn];
vector<pair<int, int>> adj[mn];
priority_queue<pair<int, int>> pq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  while(m--){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  pq.push({0, 1});
  while(!pq.empty()){
    int w = -pq.top().first, cur = pq.top().second;
    pq.pop();
    if(d[cur].size() == k) continue;
    d[cur].push_back(w);
    for(auto nxt : adj[cur])
      pq.push({-(w + nxt.first), nxt.second});
  }
  for(int i = 1; i <= n; ++i){
    if(d[i].size() < k) cout << -1 << '\n';
    else cout << d[i][k-1] << '\n';
  }
}
