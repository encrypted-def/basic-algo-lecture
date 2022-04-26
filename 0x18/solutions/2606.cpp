// Authored by : breadman98
// Co-authored by : -
// http://boj.kr/9db7d8a32edf46739c3324c5fa86cc3f
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

} 
vector<int> adj[101];
bool vis[101];

int n,m; // n:컴퓨터 수, m:네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수

void bfs(){
  queue<int> q;
  q.push(1);
  vis[1] = true;

  int cnt = 0;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
      cnt++;
    }
  }
  cout<<cnt;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>m;
  while(m--){
    int u,v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
   }
   bfs();
}
