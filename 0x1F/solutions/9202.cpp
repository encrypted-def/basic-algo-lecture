// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/4a25f25dd59440fe9d018dd22e20d265
#include <bits/stdc++.h>
using namespace std;

const int MX = 300000 * 8 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][26];
bool chk[MX];

bool vis[4][4];
char board[4][4];
unordered_map<string, int> cnt;
vector<string> keys[9];

int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int n;

int ctoi(char c){
  return c - 'A';
}

void insert(string& s){
  keys[s.size()].push_back(s);
  int cur = ROOT;
  for(char c : s){
    int& next = nxt[cur][ctoi(c)];
    if(next == -1) next = unused++;
    cur = next;
  }
  chk[cur] = 1;
}

void find(int cx, int cy, int cur, string s){
  char c = board[cx][cy];
  s += c;

  int& next = nxt[cur][ctoi(c)];
  if(next == -1) return;
  if(chk[next]) cnt[s]++;

  for(int dir = 0; dir < 8; dir++){
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];

    if(nx >= 4 || nx < 0 || ny >= 4 || ny < 0) continue;
    if(vis[nx][ny]) continue;

    vis[nx][ny] = 1;
    find(nx, ny, next, s);
    vis[nx][ny] = 0;
  }
}

void solve(){
  int scnt = 0, sc = 0;
  string lw = "";

  for(int i = 8; i > 0; i--)
    for(auto k : keys[i]) cnt[k] = 0;

  for(int x = 0; x < 4; x++)
    for(int y = 0; y < 4; y++) {
      vis[x][y] = 1;
      find(x, y, ROOT, "");
      vis[x][y] = 0;
    }

  for(int i = 8; i > 0; i--)
    for(auto k : keys[i])
      if(cnt[k] >= 1) {
        sc += score[k.size()];
        if(lw == "") lw = k;
        scnt++;
      }

  cout << sc << ' ';
  cout << lw << ' ';
  cout << scnt << '\n';
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i] + 26, -1);

  cin >> n;
  while(n--){cin >> s; insert(s);}
  for(int i = 1; i <= 8; i++)
    sort(keys[i].begin(), keys[i].end());

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++)
      cin >> board[j];
    solve();
  }
}
/*
- 단어 사전에 들어있는 단어를 트라이 구조에 넣습니다.
- 백트래킹으로 인접한 문자(대각선 포함)에 접근하며 주어진 4x4 Boggle 보드를 확인합니다.
- 해시를 활용해 사전에 등재된 단어를 셉니다.
- Note: 메모리 282356 kB, 시간 4424 ms
*/