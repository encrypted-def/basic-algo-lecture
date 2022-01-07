// Authored by : jihwan0123
// Co-authored by : -
// http://boj.kr/dba6d95717e54c01ad72e26ac0940dc2
#include <bits/stdc++.h>
using namespace std;
string board[5];
void rotate(int x, int dir) // 회전
{
  string tmp = "";
  if (dir == -1) // 반시계 방향
  {
    for (int i = 1; i < 8; i++)
      tmp.push_back(board[x][i]);
    tmp.push_back(board[x][0]);
    board[x] = tmp;
  }
  else // 시계 방향
  {
    tmp.push_back(board[x][7]);
    for (int i = 0; i < 7; i++)
      tmp.push_back(board[x][i]);
    board[x] = tmp;
  }
}
void func(int x, int dir, vector<pair<int, int>> &wheels)
{
  int s = x;
  int e = x;
  int sd = dir;
  int ed = dir;
  while (s > 1) // x 왼쪽 체크
  {
    if (board[s][6] != board[s - 1][2])
    {
      sd *= -1; s--;
      wheels.push_back({s, sd});
    }
    else
      break;
  }
  while (e < 4) // x 오른쪽 체크
  {
    if (board[e][2] != board[e + 1][6])
    {
      ed *= -1; e++;
      wheels.push_back({e, ed});
    }
    else
      return;
  }
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= 4; i++)
    cin >> board[i];
  int k;
  cin >> k;
  while (k--)
  {
    int x, dir;
    cin >> x >> dir;
    vector<pair<int, int>> wheels;
    wheels.push_back({x, dir});
    func(x, dir, wheels);
    // 회전
    for (auto w : wheels)
      rotate(w.first, w.second);
  }
  int ans = 0;
  for (int i = 1; i <= 4; i++)
    if (board[i][0] == '1')
      ans += (1 << (i - 1));
  cout << ans;
}