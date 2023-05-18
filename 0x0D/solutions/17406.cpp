// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/3eccdc57ec9741f69a20c5a7d2d3bdd0
#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
const int INF = 0x7f7f7f7f;

int n, m, k, ans = INF;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int A[MX][MX], a[MX][MX], b[MX][MX];

vector<tuple<int, int, int>> op;
vector<int> perm;

void rot(int x, int y, int s_lim) {
  for(int s = 1; s <= s_lim; s++) {
    int cx = x - s, cy = y - s;
    int dir = 0;
    while(dir != 4) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < x - s || ny < y - s) { dir++; continue; }
      if(nx > x + s || ny > y + s) { dir++; continue; }
      b[nx][ny] = a[cx][cy];
      swap(cx, nx); swap(cy, ny);
    }
  }
}

void solve() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      a[i][j] = b[i][j] = A[i][j];

  for(auto seq : perm) {
    auto [r, c, s] = op[seq];
    rot(r, c, s);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        a[i][j] = b[i][j];
  }

  int tmp_ans = INF, tot;
  for(int i = 0; i < n; i++) {
    tot = 0;
    for(int j = 0; j < m; j++)
      tot += a[i][j];
    tmp_ans = min(tmp_ans, tot);
  }
  ans = min(tmp_ans, ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> A[i][j];

  perm.resize(k);
  op.resize(k);

  for(int i = 0; i < k; i++)
    perm[i] = i;
  
  for(int i = 0; i < k; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    op[i] = {r - 1, c - 1, s};
  }

  do { solve(); } while(
      next_permutation(perm.begin(), perm.end())
  );
  cout << ans;
}
/*
회전 연산 정보 r, c, s를 op 배열에 순차적으로 기록한다(73번째 줄).
0-indexed를 기반으로 작성했으므로, r과 c의 값은 하나씩 감소시킨다.

perm은 연산 순서를 next_permutation으로 결정하며 수행한다(76-78번째 줄).
perm 값이 i인 경우 i번 회전 연산을 수행한다.

A배열에는 원 배열의 값을 저장해놓고 solve 함수를 수행할 때마다
a 배열과 b 배열에 값을 옮겨 사용한다(33-35번째 줄).
결정된 perm을 따라서 op 배열의 값 (r, c, s)를 불러오고,
이를 인자로 전달해 rot함수를 실행한다.

rot함수는 중심부인 x, y에서 회전 팔 길이 s를 증가시키며 회전을 수행한다(18-29번째 줄).
시작점인 cx, cy는 x - s, y - s로 설정한 뒤
dir을 0에서부터 증가시키며 nx, ny를 반시계 방향으로 갱신한다.
범위가 x - s, y - s, x + s, y + s를 벗어나면 dir을 증가시킨다.
이후 b[nx][ny]에 a[cx][cy] 값을 넣고, nx, cx 값을 교체, ny, cy 값을 교체한다
dir이 4가 되면 해당 로직을 끝낸다(21-28번째 줄).

b 배열에는 새롭게 업데이트된 값들을 저장하므로,
b 배열 값들을 a 배열로 갱신시킨다.

이후, 배열 내 최솟값을 구한 뒤 답과 비교하여 갱신한다(45-52번째 줄).
*/