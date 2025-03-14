// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog, haneulkimdev
// http://boj.kr/9b8af3acccc745f186ec88f36af38019
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MX = 120;
int t, h, w;
string keystr;
char board[MX][MX];
int vis[MX][MX];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    cin >> h >> w;
    queue<pair<int, int>> Q;
    queue<pair<int, int>> door[26]; // 아직 키가 없어서 방문하지 못한 곳의 좌표를 저장. 추후 키가 생기면 방문 예정.
    int key[26] = {};
    int cnt = 0;
    for(int i = 0; i <= h + 1; i++){
      fill(vis[i], vis[i] + w + 2, 0);
      fill(board[i], board[i] + w + 2, 0);
    }
    for(int i = 1; i <= h; i++)
      for(int j = 1; j <= w; j++) cin >> board[i][j];
    cin >> keystr;

    for(auto c : keystr) key[c - 'a'] = 1;
    Q.push({0, 0});
    vis[0][0] = 1;
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      for(int dir = 0; dir < 4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
        if(vis[nx][ny] || board[nx][ny] == '*') continue;
        vis[nx][ny] = 1;
        // 1. 열쇠
        if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
          int k = board[nx][ny] - 'a';
          key[k] = 1;
          while(!door[k].empty()){
            auto ndoor = door[k].front(); door[k].pop();
            Q.push({ndoor.X, ndoor.Y});
          }
        }
        // 2. 문
        else if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z'){
          int k = board[nx][ny] + 32 - 'a'; // 대문자를 소문자로 변경
          if (!key[k]){ 
            door[k].push({nx, ny});
            continue;
          }
        }
        // 3. 문서
        else if(board[nx][ny] == '$') cnt++;
        Q.push({nx, ny});
      }
    }
    cout << cnt << "\n";
  }
}
