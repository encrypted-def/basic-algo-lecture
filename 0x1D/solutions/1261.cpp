// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/d80082187a144148ac6826a99624c2e0
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
bool b[102][102];
int d[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve(){
  priority_queue< tuple<int, int, int>,
                  vector<tuple<int, int, int>>,
                  greater<tuple<int, int, int>> > pq;
  d[1][1] = 0;
  pq.push({0, 1, 1});
  while(!pq.empty()){
    int cw, cx, cy;
    tie(cw, cx, cy) = pq.top(); pq.pop();
    if(d[cx][cy] != cw) continue;

    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx > n || nx < 1) continue;
      if(ny > m || ny < 1) continue;
      int nw = cw + b[nx][ny];
      if(nw < d[nx][ny]) {
        d[nx][ny] = nw;
        pq.push({nw, nx, ny});
      }
    }
  }
  return d[n][m];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> m >> n;
  for(int i = 1; i <= n; i++){
    string str; cin >> str;
    for(int j = 1; j <= m; j++)
      b[i][j] = str[j-1] - '0';
  }
  for(int i = 1; i <= n; i++)
    fill(d[i] + 1, d[i] + m + 1, INF);

  cout << solve();
}
/*
도착 장소인 (n, m)의 값을 그대로 활용하기 위해
배열을 1-indexed로 사용합니다.

벽을 부수는 횟수를 최소 하는 길을 찾는 문제기 때문에
벽을 부수는 횟수를 비용으로 둡니다.

튜플을 담는 최소힙을 선언하고,
초기 위치와 비용을 넣습니다.

이후 최소힙을 활용해 다익스트라 알고리즘을 활용합니다.

다음으로 건너갈 위치가 갈 수 있는 곳이면 동일한 비용을,
다음으로 건너갈 위치가 벽인 경우 비용을 1 추가해 최소힙에 넣습니다.

다음 위치가 방문했던 곳이라도 기록된 비용보다
더 적은 비용으로 접근 가능할 경우
비용을 갱신하고 최소힙에 다시 넣습니다.
모든 과정을 마친 후 최소힙이 비면 d[n][m]을 반환합니다.

가로 크기 100, 세로 크기 100으로 제한되므로,
최대 10^4 수준의 답이 나오므로 solve는 int 변수를 반환하게 둡니다.
*/