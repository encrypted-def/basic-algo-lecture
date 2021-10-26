// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/aa20712f02e24cfda43bfd249844ef03
#include <bits/stdc++.h>
using namespace std;

bool isPuyo; // 뿌요가 터졌는지 여부
bool vis[12][6]; // 필드 방문 여부
string board[12]; // 필드 상태
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int ans;

// vis 배열 초기화
void resetVis(){
  for(int i = 0; i < 12; ++i)
    for(int j = 0; j < 6; ++j)
      vis[i][j] = false;
}

// bfs 탐색을 기반으로 같은 색의 뿌요를 지우는 함수
void puyo(int x, int y){
  bool doErase = false; // 뿌요를 지워야하는지 여부
  vis[x][y] = true;
  char color = board[x][y];
  queue<pair<int, int> > q;
  vector<pair<int, int>> tmp; // tmp: 4개 이상일 경우 뿌요를 지우기 위해 위치를 저장하는 vector
  q.push({x, y}); tmp.push_back({x, y});
  while(!q.empty()){
    pair<int, int> cur = q.front(); q.pop();
    for(int i = 0; i < 4; ++i){
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
      // 빈 칸이거나 색이 다를 경우 무시
      if(vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
      vis[nx][ny] = true;
      q.push({nx, ny}); tmp.push_back({nx, ny});
    }
  }

  // 4개 이상 연결되어 있을 경우 연결된 뿌요 삭제
  if(tmp.size() >= 4){
    isPuyo = true;
    for(auto cur : tmp)
      board[cur.first][cur.second] = '.';    
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 12; ++i)
    cin >> board[i];
  do{
    isPuyo = false; // 뿌요가 터졌는지 여부
    for(int i = 0; i < 6; ++i){
      // 필드의 빈 칸을 모두 뿌요 위로 올림
      for(int j = 10; j >= 0; --j){
        int tmp = j;
        // 빈 칸일 경우 위치 변경
        while(tmp<11&&board[tmp+1][i]=='.'){
          swap(board[tmp][i], board[tmp+1][i]);
          ++tmp;
        }
      }
    }
    // 필드 상의 터져야 하는 모든 뿌요 처리
    for(int i = 0; i < 12; ++i)
      for(int j = 0; j < 6; ++j)
        if(!vis[i][j]&&board[i][j]!='.')
          puyo(i, j);

    if(isPuyo) ++ans; // 연쇄 수 추가
    resetVis();
  }while(isPuyo); // 더 이상 뿌요가 터지지 않을 때까지 반복
  cout << ans;
}

/*
현재 코드는 뿌요를 바닥으로 내리는 처리를 O(6 * 12 * 12)에 처리하고 있는데
2048 문제에서 tilt 함수의 시간복잡도를 개선한 것과 비슷한 로직을 이용하면
O(6*12)에 처리할 수도 있다.
*/
