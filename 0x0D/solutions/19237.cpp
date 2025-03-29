// Authored by : H2ll0World
// Co-authored by : -
// http://boj.kr/2c028878405043a6b1edb0ac2ab67f07

// 어른 상어
#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
pair<int, int> board[400][400]; // (냄새 지속시간, 냄새 주인)
int preBoard[400][400]; // 
pair<int, int> pos[1001]; // 상어의 위치
bool live[1001]; // 상어의 생존여부
int curDir[1001]; // 상어의 방향
int dirPriority[1001][4][4]; // 상어의 방향 우선순위

// 북쪽을 기준으로 시계방향으로 변함
int changeDir(int dir){
  if(dir == 1)
    return 0;
  else if(dir == 2)
    return 2;
  else if(dir == 3)
    return 3;
  else if(dir == 4)
    return 1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  for (int i = 0; i < 400; ++i)
    fill(board[i], board[i] + 400, std::make_pair(0, 0));

  for (int i = 0; i < 400; ++i)
    fill(preBoard[i], preBoard[i] + 400, -1);
    
  fill(live, live + 1001, true);

  int n, m, k; // n : 격자의 크기 // m : 상어의 숫자 // k : 냄새의 지속 시간
  cin >> n >> m >> k;

  int tmp;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      cin >> tmp;
      if(tmp != 0) {
        pos[tmp] = make_pair(i, j);
        board[i][j].first = k; //
        board[i][j].second = tmp; 
      }
    }
    
  for(int i = 1; i <= m; i++){
    cin >> tmp;
    curDir[i] = changeDir(tmp);
  }

  for(int i = 1; i <= m; i++)
    for(int j = 1; j <= 4; j++) 
      for(int z = 0; z < 4; z++){
        cin >> tmp;
        dirPriority[i][changeDir(j)][z] = changeDir(tmp);
      }

  int dir;
  int ny, nx;
  int liveCnt = m;
  int time;
  for(time = 1; time <= 1002; time++){
    // 상어 이동
    if(liveCnt == 1) break;
    for(int i = 1; i <= m; i++){
      if(live[i] == 0) continue; // 나간 경우

      int j;
      bool fir = 1; // 자신의 냄새
      int myY, myX;
      int myDir;
      for(j = 0; j < 4; j++){
        dir = dirPriority[i][curDir[i]][j];
        ny = pos[i].first + dy[dir]; nx = pos[i].second + dx[dir];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n) // OOB : Out of Bound
          continue;

        if(board[ny][nx].first == time + k && time > preBoard[ny][nx]){ // 1. 냄새가 없는 칸이 있는 경우, 우선순위가 높은 상어와 같이 방문한 경우
          // 우선순위가 높은 상어가 있음 
          live[i] = 0; // 쫓겨남
          liveCnt--;
          break;
        }else if(time <= board[ny][nx].first){ // 냄새가 남아있어서 방문 X
          if(fir && board[ny][nx].second == i){ // 그 냄새가 자신의 것인 경우
            myY = ny; myX = nx;
            myDir = dir;
            fir = 0;
          }
          continue;
        }
        preBoard[ny][nx] = board[ny][nx].first;
        board[ny][nx].first = time + k;
        board[ny][nx].second = i;

        pos[i].first = ny;
        pos[i].second = nx;
        curDir[i] = dir;
                
        break;
      }
      if(j == 4){ // 2. 냄새가 없는 칸이 없는 경우 -> 자신의 냄새로 이동
        preBoard[myY][myX] = board[myY][myX].first;
        board[myY][myX].first = time + k;
        pos[i].first = myY; pos[i].second = myX;
        curDir[i] = myDir;
      }
    }
  }

  time--;
  if(time > 1000){
    cout << -1 << '\n';
    return 0;
  }

  cout << time << '\n';
  return 0;
}
