// http://boj.kr/51351692972f4da78400de750267acc6
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32001];
int deg[32001];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  while(m--){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    deg[b]++;
  }
  queue<int> q;
  for(int i = 1; i <= n; i++){
    if(deg[i] == 0) q.push(i);
  }
  while(!q.empty()){
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for(int nxt : adj[cur]){
      deg[nxt]--;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }
}