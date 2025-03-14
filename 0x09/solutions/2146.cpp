// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/1b1d9408543c440885788af2cfade28c
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MX = 102;
int board[MX][MX];
int vis[MX][MX];
int dist[MX][MX];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int n, cnt = 0;
queue<pair<int,int>> Q;
vector<int> ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) cin >> board[i][j];

  // cnt는 섬의 번호를 의미, board[i][j]의 값이 같은 경우 같은 섬임
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 0 || vis[i][j]) continue;
      cnt++;
      vis[i][j] = 1;
      board[i][j] = cnt;
      Q.push({i,j});
      while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            board[nx][ny] = cnt;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
      }
    }
  }

  for(int i = 0; i < n; i++)
    fill(dist[i], dist[i] + n, -1);

  int ans = 999999;
  // 모든 육지 (i, j) 각각에 대해 bfs를 진행. 이 때 board[i][j]와
  // board[nx][ny]가 다른 최초의 (nx, ny)를 찾으면 (i, j)에서 시작하는 다리의 길이를 계산 가능.
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] != 0){
        Q.push({i,j});
        dist[i][j] = 0;
        bool escape = false; // 다리를 찾으면 이 변수를 true로 만들어 bfs를 중단. 있으나 없으나 big O의 시간복잡도 관점에서는 동일하나 약간의 최적화 가능.
        while(!Q.empty() && !escape){
          auto cur = Q.front(); Q.pop();
          for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] >= 0 || board[i][j] == board[nx][ny]) continue;
            if(board[nx][ny] != 0 && board[i][j] != board[nx][ny]){
              ans = min(ans, dist[cur.X][cur.Y]);
              while(!Q.empty()) Q.pop();
              escape = true;
              break;
            }            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
          }
        }
        for(int i = 0; i < n; i++)
          fill(dist[i], dist[i] + n, -1);
      }
    }
  }
  cout << ans;
}

/*
가장 직관적으로 떠올릴 수 있는 풀이. 이 풀이는 bfs를 육지의 개수(=최대 O(n^2)개)만큼
진행하고 bfs 1번은 O(n^2)의 시간복잡도이기 때문에 O(n^4)에 동작한다.

이 때 실제로 어떤 입력이 들어오면 O(n^4)에 동작할지 고민을 해볼 필요가 있는데,

1 1 1 1 1 1 1 1 1 1 1 ... 1 1 
1 0 1 0 1 0 1 0 1 0 1 ... 0 1
1 0 1 0 1 0 1 0 1 0 1 ... 0 1
.
.
.
1 0 1 0 1 0 1 0 1 0 1 ... 0 1
0 0 0 0 0 0 0 0 0 0 0 ... 0 0
.
.
.
0 0 0 0 0 0 0 0 0 0 0 ... 0 0
1 0 1 0 1 0 1 0 1 0 1 ... 0 1
.
.
.
1 0 1 0 1 0 1 0 1 0 1 ... 0 1
1 1 1 1 1 1 1 1 1 1 1 ... 1 1 

과 같은, 마치 빗 2개가 적당한 거리를 두고 있는 괴상한 형태로 설계를 해야 O(n^4)이 걸리는 데이터를 만들 수 있다.

단순히
1 1 1 1 1 1 1 1 1 1 1 ... 1 1
.
.
.
1 1 1 1 1 1 1 1 1 1 1 ... 1 1
0 0 0 0 0 0 0 0 0 0 0 ... 0 0
.
.
.
0 0 0 0 0 0 0 0 0 0 0 ... 0 0
1 1 1 1 1 1 1 1 1 1 1 ... 1 1
.
.
.
1 1 1 1 1 1 1 1 1 1 1 ... 1 1

과 같이 데이터를 만들면 O(n^4) 대신 O(n^3)이 걸리는데, 왜 위와 같은 괴상한 형태로 만들어야 O(n^4)이고
이 데이터는 O(n^3)인지 고민을 해보면 앞으로 bfs에서의 시간복잡도 분석에 도움이 될 것으로 보인다.

다행히 n = 100이어서 O(n^4)로도 통과에는 문제가 없다. 비록 문제를 풀 때 실제로 O(n^4)를
필요로 하는 데이터가 있는지 고민을 해보는건 시간복잡도를 제대로 따져보기 위해서는
진행되어야 하는 과정이었지만 이 문제의 경우 그러한 데이터를 구성하는게 꽤 어려웠기 때문에
이 과정을 생략했더라도 그럴 수 있으나 풀이를 생각한 후 풀이의 시간복잡도를 아예
고민해보지 않았거나, O(n^2) 혹은 O(n^3)으로 시간복잡도를 잘못 인지했다면 시간복잡도에
대해 항상 신경을 써야하는 점을 기억하도록 하자.

또한 이 문제는 bfs를 2번만 사용해 O(n^2) 문제를 풀어내는 풀이가 존재한다. 해당 풀이는
별해에 등록할 예정이니 코드를 확인해보는 것을 권장하고 자세한 설명글은

https://infossm.github.io/blog/2019/03/07/%EC%BD%94%EB%94%A9%ED%85%8C%EC%8A%A4%ED%8A%B8-%EB%8C%80%EB%B9%84-%ED%8A%B9%EA%B0%95/

의 52p부터 확인하면 된다.
*/
