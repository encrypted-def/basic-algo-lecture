// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/0a82da10ab7b4e8782d5b8e9d3296dba
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 테트로미노의 모든 조합
pair<int, int> tetro[19][4] = {
    // 청록색 블록
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    // 노랑색 블록
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
    // 주황색 블록
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 0}},

    {{0, 1}, {1, 1}, {2, 1}, {0, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    // 초록색 블록
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
    // 자주색 블록
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {1, 0}}};
int board[505][505];
int n, m;

int bruteforce(int x, int y) {
  int mx = 0;
  for (int i = 0; i < 19; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++)
      sum += board[x + tetro[i][j].X][y + tetro[i][j].Y];
    mx = max(mx, sum);
  }
  return mx;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans = max(ans, bruteforce(i, j));
  cout << ans;
}
