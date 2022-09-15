// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/76d3c341789a4dafa200633dcfb8fbd9
#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<int> pt[52];
vector<int> adj[52];
bool tr[52];
bool vis[52];

void bfs() {
  for(int i = 1; i <= n; i++) {
    if(!tr[i]) continue;
    fill(vis, vis + n + 2, 0);

    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(int nxt : adj[cur]) {
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        tr[nxt] = 1;
        q.push(nxt);
      }
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> t;
  while(t--) {
    int x; cin >> x;
    tr[x] = 1;
  }

  for(int i = 0; i < m; i++) {
    int no; cin >> no;

    int prv, nxt;
    cin >> prv;
    pt[i].push_back(prv);

    while(--no) {
      cin >> nxt;
      pt[i].push_back(nxt);
      adj[nxt].push_back(prv);
      adj[prv].push_back(nxt);
      swap(prv, nxt);
    }
  }

  bfs();

  int cnt = 0;
  for(int i = 0; i < m; i++) {
    bool known = 0;
    for(int p : pt[i]) if(tr[p]) known = 1;
    if(!known) cnt++;
  }
  cout << cnt;
}