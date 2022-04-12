// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/ac52db795ae444528cb33b2a795476dd
#include <bits/stdc++.h>
using namespace std;
bool path[105][105];
vector<int> adj[105];
bool vis[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,v;
  cin >> n;

  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      cin >> v;
      if(v)
        adj[i].push_back(j);
    }
  }
  //i번째 노드에서 bfs를 이용해 노드 v에 도달 할 수 있다면
  //i -> v인 경로가 존재한다.
  for(int i{1}; i<=n; ++i) {
    fill(vis,vis+101,false);
    queue<int> q {};
    q.push(i);
    vis[i] = true;

    while(!q.empty()) {
      auto u = q.front();
      q.pop();

      for(auto v : adj[u]) {
        if(vis[v] && v == i)
          path[i][v] = true;
        if(vis[v]) continue;
        vis[v] = true;
        path[i][v] = true;
        q.push(v);
      }
    }
  }

  for(int i{1}; i<=n; ++i) {
    for(int j{1}; j<=n; ++j) {
      cout << path[i][j] << ' ';
    }
    cout << '\n';
  }
}
