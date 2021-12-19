// http://boj.kr/6e5dc7014683424aa8ebf2214fc0733d
#include <bits/stdc++.h>
using namespace std;

int n,m,st;
vector<int> adj[1001];
bool vis[1001];

// 비재귀 DFS
void dfs1(){
  stack<int> s;
  s.push(st);
  while(!s.empty()){
    int cur = s.top();
    s.pop();
    if(vis[cur]) continue;
    vis[cur] = true;
    cout << cur << ' ';
    for(int i = 0; i < adj[cur].size(); i++){
      // 스택의 특성상 정점을 역순으로 넣어야 함
      int nxt = adj[cur][adj[cur].size()-1-i];
      if(vis[nxt]) continue;
      s.push(nxt);
    }    
  }
}

// 재귀 DFS
void dfs2(int cur){
  vis[cur] = true;
  cout << cur << ' ';
  for(auto nxt : adj[cur]){
    if(vis[nxt]) continue;    
    dfs2(nxt);
  }
}

void bfs(){
  queue<int> q;
  q.push(st);
  vis[st] = true;
  while(!q.empty()){
    int cur = q.front();
    cout << cur << ' ';
    q.pop();
    for(auto nxt : adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }    
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> st;
  while(m--){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // 번호가 작은 것 부터 방문하기 위해 정렬
  for(int i = 1; i <= n; i++)
    sort(adj[i].begin(), adj[i].end());
  dfs1(); // dfs2(st);
  cout << '\n';
  fill(vis+1, vis+n+1, false);
  bfs();
}