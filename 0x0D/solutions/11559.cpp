// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/a906c6d1a6c74ce8a875ee2ba1145e11
#include <bits/stdc++.h>
using namespace std;

bool isPuyo; // 뿌요가 터졌는지 여부
bool vis[12][6]; // 필드 방문 여부
char board[12][6]; // 필드 상태
int dirX[] = {1, 0, -1, 0};
int dirY[] = {0, 1, 0, -1};
int ans;

// vis 배열 초기화
void resetVis(){
  for(int i = 0; i < 12; ++i)
    for(int j = 0; j < 6; ++j)
      vis[i][j] = false;
}

// bfs 탐색을 기반으로 같은 색의 뿌요를 지우는 함수
void puyo(int y, int x){
  bool doErase = false; // 뿌요를 지워야하는지 여부
  int cnt = 1;
  vis[y][x] = true;
  char color = board[y][x];
  queue<pair<int, int> > q, tar; // tar: 4개 이상일 경우, 뿌요를 지우기 위해 위치를 저장하는 큐
  q.push({y, x}); tar.push({y, x});
  while(!q.empty()){
    pair<int, int> t = q.front(); q.pop();
    for(int i = 0; i < 4; ++i){
      int nx = t.second + dirX[i];
      int ny = t.first + dirY[i];
      if(nx<0||nx>=6||ny<0||ny>=12) continue;
      // 빈 칸이거나 색이 다를 경우 무시
      if(vis[ny][nx]||board[ny][nx]=='.'||board[ny][nx]!=color) continue;
      vis[ny][nx] = true;
      q.push({ny, nx}); tar.push({ny, nx});
      ++cnt;
      // 연결된 뿌요가 4개 이상일 경우 삭제
      // 단, 5개 이상일 경우에도 모든 뿌요를 지워야 하므로 반복문은 끝까지 진행
      if(cnt>=4) doErase = true;
    }
  }

  // 연결된 뿌요 삭제
  if(doErase){
    isPuyo = true;
    while(!tar.empty()){
      pair<int, int> t = tar.front(); tar.pop();
      board[t.first][t.second] = '.';
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 12; ++i){
    string str;
    cin >> str;
    for(int j = 0; j < 6; ++j)
      board[i][j] = str[j];
  }

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
