// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/4de63bcfae1f4c529037d0b03050a65d
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> adj[505];
int dist[505];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = 0;
  queue<int> q;
  q.push(1);
  dist[1] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    if(dist[cur] > 2) // 친구의 친구는 거기서 bfs를 더 하지 않고 stop
      continue;
    for(auto nxt : adj[cur]){
      if(dist[nxt] > 0)
        continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
      ans++;
    }
  }
  cout << ans << '\n';
}

/*
DFS로 풀이를 해도 괜찮지만 그 경우에는 같은 사람이 친구이자 친구의 친구인 경우의 처리에 주의.
ex)
1-2
1-3
2-3
3-4
3-5
에서는 3이 상근이의 친구이자 친구의 친구임. 이 때 처리를 잘못하면
자칫 4, 5를 포함시키지 않을 수도 있음.
*/
