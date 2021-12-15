// Authored by : erolf0123
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/30d197c430734d1c8fff80bb8919510a
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101005];
int dist[101005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= k; j++) {
      int x;
      cin >> x;
      adj[n + i].push_back(x); // n+i번 정점 : i번째 하이퍼튜브의 정점
      adj[x].push_back(n + i);
    }
  }
  fill(dist, dist+n+m+1, -1);

  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int nxt: adj[cur]){
      if(dist[nxt] != -1) continue;
      q.push(nxt);
      dist[nxt] = dist[cur] + 1;
    }
  }
  
  if(dist[n] == -1) cout << dist[n];
  else cout << dist[n]/2 + 1;
}

/*
한 하이퍼튜브에 연결된 역들에 대해 전부 서로 간선을 연결할 수는 없다.
대신 각 하이퍼튜브 자체를 정점으로 생각해 그래프를 만들고 거기서 BFS를
진행하면 된다. 
*/
