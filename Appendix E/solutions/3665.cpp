// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/a4497307382e4a2dad1cc8cf86eafcdc
#include <bits/stdc++.h>
using namespace std;

const int mn = 505;
int t, n, m, indeg[mn], pre[mn];
bool adj[mn][mn];
queue<int> q;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; ++i)
      cin >> pre[i];
    for(int i = 0; i < n; ++i){
      for(int j = i+1; j < n; ++j){
        adj[pre[i]][pre[j]] = 1;
        ++indeg[pre[j]];
      }
    }
    cin >> m;
    while(m--){
      int u, v;
      cin >> u >> v;
      adj[u][v] = !adj[u][v];
      adj[v][u] = !adj[v][u];
      if(adj[u][v]){
        ++indeg[v];
        --indeg[u];
      }
      else{
        ++indeg[u];
        --indeg[v];
      }
    }
    
    for(int i = 1; i <= n; ++i)
      if(indeg[i] == 0) q.push(i);

    vector<int> res;
    while(!q.empty()){
      int cur = q.front(); q.pop();
      res.push_back(cur);
      for(int nxt = 1; nxt <= n; ++nxt){
        if(adj[cur][nxt] == 0) continue;
        if(--indeg[nxt] == 0) q.push(nxt);
      }
    }
    
    fill(indeg, indeg+n+1, 0);
    for(int i = 1; i <= n; ++i) fill(adj[i], adj[i]+n+1, 0);

    if(res.size() != n){
      cout << "IMPOSSIBLE" << '\n';
      continue;
    }
    for(int u : res)
      cout << u << ' ';
    cout << '\n';
  }
}

/*
?를 출력해야하는 상황이라는 것은 곧 두 팀간의 선후관계를 확정할 수 없다는 것인데,
그런 상황이 존재하려면 일단 어떤 두 팀 사이에 간선이 없어야합니다.
하지만 이 문제에서는, 작년 순위에서는 임의의 두 팀 사이에 관계가 존재하고, 상대 순위가 바뀐다고 하더라도 관계가 사라지는 것은 아닙니다.
따라서 ?를 출력하는 상황은 존재하지 않습니다.
*/
