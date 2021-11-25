// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f34eee0ca14f450c9ad0a0e9deefc033
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int m, n, k;
int a, b, c, d;
int board[102][102];
vector<int> v;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void fillBoard(int a, int b, int c, int d){
  for(int i = a; i < c; i++)
    fill(board[i]+b, board[i]+d, 1); // 직사각형 내부 1 표시
}

int bfs(int i, int j){
  int cnt = 0;
  queue<pair<int,int>> q;
  board[i][j] = 1; // 방문
  q.push({i,j}); // 푸시

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    cnt++;

    for(int i = 0; i < 4; i++){
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 1) continue;
      else{
        board[nx][ny] = 1;  // 첫 방문이라면 방문표시
        q.push({nx, ny}); // 큐에 넣기
      }
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;

  while(k--){
    cin >> a >> b >> c >> d;
    fillBoard(a, b, c, d);
  }

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { // 0인 영역에서 시작하기
      if (!board[i][j])
        v.push_back(bfs(i, j));
    }
  }
  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for(auto a : v) cout << a << ' ';

  return 0;
}

/*
문제에서 주어진 좌표의 방향을 무시하고 (x,y)에 대해
(0,0) (0,1) (0,2) ...
(1,0) (1,1) (1,2) ...
으로 배치함. 이 경우 행은 n개, 열은 m개인 n by m 배열이 됨.
*/
