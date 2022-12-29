// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/8fd2c4a42ad5491caa20c09336e319c5
#include <bits/stdc++.h>
using namespace std;

const int NMX = 10'002;

int mx;
int sc[NMX];
vector<int> adj[NMX];
bool vis[NMX];

void trav(int cur) {
  vis[cur] = 1;
  sc[cur]++;
  mx = max(mx, sc[cur]);
  for(int nxt : adj[cur]) {
    if(vis[nxt]) continue;
    trav(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  fill(sc, sc + NMX, 0);
  for(int i = 1; i <= n; i++) {
    fill(vis, vis + NMX, 0);
    trav(i);
  }

  for(int i = 1; i <= n; i++)
    if(sc[i] == mx) cout << i << ' ';
}