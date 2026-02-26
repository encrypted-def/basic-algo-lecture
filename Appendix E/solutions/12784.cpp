// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/f9af78fd8e5246439d180420f8a57181
#include <bits/stdc++.h>
using namespace std;

const int mn = 1005, md = 25;
int t, n, m;
vector<pair<int, int>> adj[mn]; // {향하는 정점, 간선의 가중치} 형태로 저장

/*
dfs(cur) = 정점 cur을 루트로 하는 서브 트리에서 cur과 리프노드들과의 연결을 끊기 위해 필요한 최소 다이너마이트의 개수.
         = cur의 모든 자식 ch에 대해 min(cur-ch 다리 폭파 비용, dfs(cur, ch)) 값의 합
*/
int dfs(int par, int cur){
  int res = 0;
  for(auto nxt : adj[cur]){
    if(nxt.first == par) continue;
    res += min(nxt.second, dfs(cur, nxt.first));
  }
  if(cur != 1 && res == 0) res = md;
  return res;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n >> m;
    while(m--){
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    cout << dfs(-1, 1) << '\n';
    for(int i = 1; i <= n; ++i)
      adj[i].clear();
  }
}
