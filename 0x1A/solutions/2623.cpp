// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ab569c7de568444cbf1cd16ed9e4fb55
#include <bits/stdc++.h>
using namespace std;

int n, m;
int id[1002];
vector<int> adj[1002];
vector<int> sq;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int no, u, v;
  for(int i = 0; i < m; i++) {
    cin >> no;
    if(no == 0) continue;
    cin >> u;
    while(--no) {
      cin >> v;
      adj[u].push_back(v);
      id[v]++;
      swap(u, v);
    }
  }

  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(!id[i]) q.push(i);

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    sq.push_back(cur);
    for(int nxt : adj[cur])
      if(--id[nxt] == 0) q.push(nxt);
  }
  if(sq.size() != n) cout << 0;
  else for(auto s : sq) cout << s << ' ';
}