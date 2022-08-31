// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/dcc73d8e52bf47508847c0322138251c
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[10005];
int vis[10005];
int ans = 0;
int cnt = 0;

void dfs(){
  stack<int> s;
  s.push(1);
  while(!s.empty()){
    if (cnt == 2) break;
    int cur = s.top(); s.pop();
    vis[cur] = 1;
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      vis[nxt] = 1;
      ans++;
      if(cur == 1) s.push(nxt);
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs();
  cout << ans;
}
