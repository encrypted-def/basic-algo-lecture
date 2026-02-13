// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/7386ea6f37f84fa7a16dcd892d847b97
#include <bits/stdc++.h>
using namespace std;

enum COLOR{
  R, G, B
};

const int mn = 5e5+5;
int n, d[mn][3], beauty[mn][3], res[mn];
vector<int> adj[mn];

int dfs(int par, int cur, int color){
  if(d[cur][color] != -1) return d[cur][color];
  d[cur][color] = 0;
  for(int nxt : adj[cur]){
    if(nxt == par) continue;
    int mx = 0;
    for(int c = R; c <= B; ++c){
      if(c == color) continue;
      mx = max(mx, dfs(cur, nxt, c));
    }
    d[cur][color] += mx;
  }
  return d[cur][color] += beauty[cur][color];
}

void btrace(int par, int cur, int color){
  res[cur] = color;
  for(int nxt : adj[cur]){
    if(nxt == par) continue;
    int mx = 0, col = 0;
    for(int c = R; c <= B; ++c){
      if(c == color || d[nxt][c] <= mx) continue;
      mx = d[nxt][c];
      col = c;
    }
    btrace(cur, nxt, col);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; ++i)
    cin >> beauty[i][R] >> beauty[i][G] >> beauty[i][B];
    
  for(int i = 1; i <= n; ++i)
    fill(d[i], d[i]+3, -1);

  int mx = 0, start_col = 0;
  for(int c = R; c <= B; ++c){
    if(dfs(-1, 1, c) <= mx) continue;
    mx = d[1][c];
    start_col = c;
  }
  btrace(-1, 1, start_col);
  
  char col[3] = {'R', 'G', 'B'};
  cout << mx << '\n';
  for(int i = 1; i <= n; ++i)
    cout << col[res[i]];
}
