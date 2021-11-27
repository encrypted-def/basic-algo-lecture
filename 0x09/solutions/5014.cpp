// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/8f34874217304e3ca3a499f672788d70
#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int dist[1000002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> f >> s >> g >> u >> d;
  fill(dist+1, dist+f+1, -1);
  
  queue<int> q;
  dist[s] = 0; // 현재 위치의 거리를 0으로 둠
  q.push(s); // s층에서 시작
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto nxt : {cur + u, cur - d}){
      if(nxt > f || nxt <= 0 || dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }

  if(dist[g] == -1) cout << "use the stairs";
  else cout << dist[g];
}
