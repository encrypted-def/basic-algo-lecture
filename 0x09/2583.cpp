// Authored by : std-freejia
// Co-authored by :
// http://boj.kr/15af16c30a0d4c519eb9ec8a5ebc7475
#include <bits/stdc++.h>
#define X first;
#define Y second;
using namespace std;

int  m, n, k;
int a, b, c, d;
int board[102][102];
vector<int> v;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void fillBoard(int a, int b, int c, int d){ // -> (b,a) (d,c)
  for(int i = b; i < d; i++){
    for(int j = a; j < c; j++) board[i][j] = 1; // 직사각형 내부 1 표시
  }
}

int bfs(int a, int b){

  int cnt = 0;
  queue<pair<int,int>> q;
  board[a][b] = 1; // 방문
  q.push({a,b}); // 푸시

  while(!q.empty()){
    int x = q.front().X;
    int y = q.front().Y;
    q.pop();
    cnt++;

    for(int i = 0; i < 4; i++){
      int tempX = x + dx[i];
      int tempY = y + dy[i];

      if(tempX < 0 || tempX >= m || tempY < 0 || tempY >= n) continue;
      if(board[tempX][tempY] == 1) continue;
      else{
        board[tempX][tempY] = 1;  // 첫 방문이라면 방문표시
        q.push({tempX, tempY}); // 큐에 넣기
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

  for(int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) { // 0인 영역에서 시작하기
      if (!board[i][j])
        v.push_back(bfs(i, j));
    }
  }
  sort(v.begin(), v.end());
  cout << v.size() << '\n';
  for(auto a : v) cout << a << ' ';

  return 0;
}