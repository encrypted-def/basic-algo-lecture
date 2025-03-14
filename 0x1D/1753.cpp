// http://boj.kr/2ecc5e3e8209416d84a6858c21448d81
#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v,e,st;

// {비용, 정점 번호}
vector<pair<int,int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단 거리 테이블
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> v >> e >> st;
  fill(d,d+v+1,INF);
  while(e--){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  d[st] = 0;
  // 우선순위 큐에 (0, 시작점) 추가
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}    
    // 거리가 d에 있는 값과 다를 경우 넘어감
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      // cur를 거쳐가는 것이 더 작은 값을 가질 경우
      // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
      d[nxt.Y] = d[cur.Y]+nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
    }
  }

  for(int i = 1; i <= v; i++){
    if(d[i] == INF) cout << "INF\n";
    else cout << d[i] << "\n";
  }
}
