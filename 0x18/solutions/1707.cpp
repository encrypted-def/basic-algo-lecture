// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/198b761b17424b898c2c68902a49373b
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;
  while(k--) {
    int v,e;
    cin >> v >> e;
    vector<vector<int>> adj(v+1);
    for(int i{}; i<e; ++i) {
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> group (v+1);
    fill(group.begin(), group.end(), 0);

    for(int i{1}; i<=v; ++i) {
      if(group[i] > 0) continue;
      queue<int> q;
      group[i] = 1;
      q.push(i);

      while(!q.empty()) {
        auto u = q.front();
        q.pop();
        //bfs를 이용해 노드 u가 1이면 인접노드를 2로
        //노드 u가 2면 인접노드를 1로 표시한다.
        //이분그래프가 될 수 없는 경우는 인접노드에서 같은 숫자가 나오는 경우
        for(auto v : adj[u]) {
          if(group[v] > 0 && group[v] == group[u]) {
            cout << "NO\n";
            goto fail;
          }
          if(group[v] > 0 && group[v] != group[u]) continue;
          group[v] = 3-group[u];
          q.push(v);
        }
      }
    }
    cout << "YES\n";

  fail:;
  }
}
