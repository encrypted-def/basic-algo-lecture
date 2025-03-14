// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/41d8838316904329a3a8615a8a3addee
#include <bits/stdc++.h>
using namespace std;

const int MX = 300000 * 8 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][26];
int chk[MX]; // 0일 경우 해당 칸이 단어의 끝이 아님을 의미, 0이 아닌 다른 값일 경우 해당 칸이 단어의 끝임을 의미
// 각 boggle판마다 방문한 chk[...]에 서로 다른 값(=mark)을 넣어줄 예정

int mark = 2; // 각 boggle판마다 방문한 표시, find 함수에서 사용됨. 각 boggle판마다 값이 달라야하기 때문에 1씩 계속 증가됨

bool vis[4][4];
char board[4][4];

int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

int ctoi(char c){
  return c - 'A';
}

void insert(string& s){
  int cur = ROOT;
  for(char c : s){
    if(nxt[cur][ctoi(c)] == -1)
      nxt[cur][ctoi(c)] = unused++;
    cur = nxt[cur][ctoi(c)];
  }
  chk[cur] = 1;
}

int point = 0, wordnum = 0; // 점수, 단어의 수
string mxlen = ""; // 최대 길이의 단어

// trie의 find 함수와 마찬가지로 보드에서 8개의 방향에 따라 진행하며 노드를 옮겨다니면 됨
// (curx, cury)는 보드에서의 현재 위치, cur는 트라이에서의 현재 정점 번호, s는 현재까지 완성한 문자열
// 재귀적으로 구현했는데 매우 헷갈릴수도.. ㅎㅇㅌ..
void find(int curx, int cury, int cur, string s){
  if(cur == -1) return; // 트라이에서 없는 칸으로 진입했을 경우
  
  // s에 적힌 단어를 보고 적절하게 처리를 해줌
  if(chk[cur] != 0 && chk[cur] != mark){ // 정점 번호 cur에서 끝나는 단어가 있으면서 이번 boggle판에서 아직 방문을 안했다면
    chk[cur] = mark;
    point += score[s.size()];
    wordnum++;
    if(s.size() > mxlen.size()) mxlen = s;
    else if(s.size() == mxlen.size() && s < mxlen) mxlen = s;
  }

  for(int dir = 0; dir < 8; dir++){
    // 다음에 (nx, ny)를 방문할 예정
    int nx = curx + dx[dir];
    int ny = cury + dy[dir];

    if(nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;
    if(vis[nx][ny]) continue;

    char c = board[nx][ny];
    vis[nx][ny] = 1;
    find(nx, ny, nxt[cur][ctoi(c)], s + c);
    vis[nx][ny] = 0;
  }
}

void solve(){
  point = 0;
  wordnum = 0;
  mxlen = "";

  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++) {
      vis[x][y] = 1;
      find(x, y, nxt[ROOT][ctoi(board[x][y])], string(1, board[x][y]));
      vis[x][y] = 0;
    }

  cout << point << ' ' << mxlen << ' ' << wordnum << '\n';
  mark++;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 26, -1);

  int w;
  cin >> w;
  while(w--){
    cin >> s;
    insert(s);
  }

  int b;
  cin >> b;
  for(int i = 0; i < b; i++){
    for(int j = 0; j < 4; j++)
      cin >> board[j];
    
    solve();    
  }
}
/*
단어 사전에 들어있는 단어를 트라이 구조에 넣습니다.
백트래킹으로 인접한 문자(대각선 포함)에 접근하며 탐색하는데 이 때 트라이 노드도 같이 탐색을 해나갑니다.
*/
