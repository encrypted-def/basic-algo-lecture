// Authored by : windowdong11
// Co-authored by : -
// http://boj.kr/472174a0b78b4e9e8285a1f4406c9a4d
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

template <class Ty, class Tx>
bool isInArea2d(pair<Ty, Tx> cur, pair<Ty, Tx> minSize, pair<Ty, Tx> maxSize) {
  return minSize.first <= cur.first && cur.first < maxSize.first
    && minSize.second <= cur.second && cur.second < maxSize.second;
}

pair<int, int> ways4[] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

char board[1000][1000];
pair<int, int> boardEnd;
int cost[1000][1000][2];
// cost[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// cost[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int n, m;

int bfs() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cost[i][j][0] = cost[i][j][1] = -1;
  cost[0][0][0] = cost[0][0][1] = 1;
  queue<pair<bool, pair<int, int>>> q;
  q.push({ false, {0, 0} });
  while (!q.empty()) {
    bool broken = q.front().first;
    pair<int, int> cur = q.front().second;
    int nextCost = cost[cur.X][cur.Y][broken] + 1;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      pair<int, int> next = { cur.X + ways4[i].X, cur.Y + ways4[i].Y };
      if (next == boardEnd) return nextCost;
      if (isInArea2d(next, { 0, 0 }, { n, m })) {
        if (broken) {
          if (board[next.X][next.Y] == '0' && cost[next.X][next.Y][1] == -1) {
            cost[next.X][next.Y][1] = nextCost;
            q.push({ 1, next });
          }
        }
        else {
          if (board[next.X][next.Y] == '0' && cost[next.X][next.Y][0] == -1) {
            cost[next.X][next.Y][0] = cost[next.X][next.Y][1] = nextCost;
            q.push({ 0, next });
          }
          else if (board[next.X][next.Y] == '1' && cost[next.X][next.Y][1] == -1) {
            cost[next.X][next.Y][1] = nextCost;
            q.push({ 1, next });
          }
        }
      }
    }
  }
  return -1;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  boardEnd = { n - 1, m - 1 };
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j];
  if (n == 1 && m == 1) cout << 1;
  else cout << bfs();
  return 0;
}
