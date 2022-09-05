// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/4f07e3e411674c49b0f68e5f9fee9f91
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int len, cnt;

unordered_map<string, int> memo;
string str;

char board[12][12];
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void solve(int times, int cx, int cy){
  if(times == len) {
    cnt++;
    return;
  }
  for(int dir = 0; dir < 8; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];
    nx = (nx + n)%n;
    ny = (ny + m)%m;
    if(board[nx][ny] == str[times]) solve(times + 1, nx, ny);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  for(int i = 0; i < n; i++)
    cin >> board[i];

  while(k--) {
    cin >> str;
    len = str.length();
    cnt = 0;
    
    if(memo[str]) {
      cout << memo[str] << '\n';
      continue;
    }

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(board[i][j] == str[0]) solve(1, i, j);

    memo[str] = cnt;
    cout << cnt << '\n';
  }
}