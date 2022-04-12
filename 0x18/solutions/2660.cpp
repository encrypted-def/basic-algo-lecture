// Authored by : ximgea
// Co-authored by : -
// http://boj.kr/a7d606c3be364083b7e76177c03c9c10
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int dist[55];
int fren[55];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  while(1) {
    int u,v;
    cin >> u >> v;
    if(u == -1 && v == -1)
      break;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  for(int i{1}; i<=n; ++i) {
    fill(dist,dist+n+1,-1);
    queue<int> q;
    q.push(i);
    dist[i] = 0;

    while(!q.empty()) {
      auto x = q.front();
      q.pop();

      for(auto v : adj[x]) {
        if(dist[v] >= 0) continue;
        dist[v] = dist[x]+1;
        q.push(v);
      }
    }
    //i번째 회원의 점수는 i번째 노드에서의 최장거리
    fren[i] = *max_element(dist,dist+n+1);
  }

  auto point = *min_element(fren+1,fren+n+1);
  int cnt = 0;
  for(int i{1}; i<=n; ++i) {
    if(fren[i] == point) cnt++;
  }

  cout << point << ' ' << cnt << '\n';
  for(int i{1}; i<=n; ++i)
    if(fren[i] == point)
      cout << i << ' ';
}
