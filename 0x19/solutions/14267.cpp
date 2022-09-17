// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/37297150d85243f58714b1dd7c6080ec
#include <bits/stdc++.h>
using namespace std;

int n, m;
int root, gr;
int p[100002];
int ans[100002];
int sc[100002];
vector<int> adj[100002];

void tr(int cur, int g) {
  g += sc[cur];
  ans[cur] += g;
  for(int nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    tr(nxt, g);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> p[i];
  for(int i = 1; i <= n; i++) {
    if(p[i] == -1) continue;
    adj[i].push_back(p[i]);
    adj[p[i]].push_back(i);
  }
  while(m--) {
    cin >> root >> gr;
    sc[root] += gr;
  }
  tr(1, 0);
  for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}