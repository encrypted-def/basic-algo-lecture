// Authored by : diyamea
// Co-authored by : -
// http://boj.kr/02b375d22ea947b2910b21dce1c13261
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
#define X first
#define Y second
int dist[1'000'005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);


  int n,m,next,tmp;
  cin >> n;
  cin >> m;
  vector<int> start {};
  for(int i{}; i<m; ++i) {
    cin >> tmp;
    start.push_back(tmp);
  }
  // 비밀번호의 최대값이 10이고 해커가 시도한 비밀번호가 3이라고 합시다.
  // 그러면 3으로 부터 안전거리가 1인 수들은 3에서 한 비트씩 뒤집어가며 구할 수 있습니다.
  // 0011 -> 0010 0001 0111 1011(1011은 10을 넘어가서 안전거리가 1이 아닙니다.)
  // 안전거리가 2인 수들은 안전거리가 1인 수들로부터 비트를 뒤집어가며 위와 동일하게 구할 수 있습니다.
  // 그러므로 시작점이 여러개인 bfs를 통해 문제를 해결 할 수 있습니다.
  fill(dist,dist+n+2,-1);

  queue<int> q {};
  for(auto& e : start) {
    dist[e] = 0;
    q.push(e);
  }

  while(!q.empty()) {
    auto cur = q.front();
    q.pop();


    for(int k{}; k<31; ++k) {
      //bitmask 검색
      if(cur & (1 << k))
        next = cur & ~(1 << k);
      else
        next = cur | (1 << k);
      if (next > n) continue;
      if (dist[next] >= 0) continue;
      dist[next] = dist[cur]+1;
      q.push(next);
    }
  }
  int ans = 0;
  for(int i{}; i<=n; ++i)
    ans = max(ans, dist[i]);
  cout << ans;
}
