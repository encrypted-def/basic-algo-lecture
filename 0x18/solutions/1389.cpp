// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/b2d18c07c50a445ca319bb2459a9644c
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define X first
#define Y second
vector<int> adj[105];
int dist[105];
int kevin[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  for(int i{}; i<m; ++i) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  //친구관계가 중복해서 들어오는 경우를 제거
  //https://blog.encrypted.gg/985?category=773649
  //"좌표압축" 참고
  for(int u{1};u<=n;++u) {
    sort(adj[u].begin(), adj[u].end());
    adj[u].erase(unique(adj[u].begin(), adj[u].end()),adj[u].end());
  }

  for(int i{1}; i<=n; ++i) {
    fill(dist, dist+n+1, -1);
    queue<int> q;
    q.push(i);
    dist[i] = 0;

    while(!q.empty()) {
      auto u = q.front();
      q.pop();

      for(auto v : adj[u]) {
        if(dist[v] >= 0) continue;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
    //케빈베이컨수는 다른 모든 유저와의 거리의 합이다.
    kevin[i] = accumulate(dist+1, dist+n+1, 0);
  }

  auto min = 0x7fffffff;
  auto person = 0;
  for(int i{1}; i<=n; ++i) {
    if(kevin[i] < min) {
      min = kevin[i];
      person = i;
    }
  }
  cout << person;
}
