// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/c25a30dd61f24dde92937343edb55a44
#include <bits/stdc++.h>
using namespace std;

const int MX = 20;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, u, v, mx, ans;

int score[MX + 2][MX + 2];
int vctcnt[MX + 2][MX + 2];
int b[MX + 2][MX + 2];
int pref[MX*MX + 2][4];

pair<int, int> ps[MX*MX + 2];
vector<tuple<int, int, int>> cand;

bool OOB(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

void setup() {
  cin >> n;
  for(int i = 1; i <= n*n; i++)
    ps[i] = {-1, -1};

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      vctcnt[i][j] = 4;
      if(i == 0 || i == n - 1) vctcnt[i][j]--;
      if(j == 0 || j == n - 1) vctcnt[i][j]--;
    }
}

void init() {
  for(int i = 0; i < n; i++)
    fill(score[i], score[i] + n, 0);
  mx = 0;
  cand.clear();
}

void setprefer() {
  cin >> u;
  for(int j = 0; j < 4; j++) {
    cin >> v;
    pref[u][j] = v;
    auto [cx, cy] = ps[v];
    if(cx == -1 && cy == -1) continue;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(OOB(nx, ny) || b[nx][ny]) continue;
      score[nx][ny]++;
      mx = max(mx, score[nx][ny]);
    }
  }
}

void setseat() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(mx == score[i][j] && !b[i][j])
        cand.push_back({-vctcnt[i][j], i, j});

  sort(cand.begin(), cand.end());
  auto [vcnt, x, y] = cand[0];

  ps[u] = pair<int, int>(x, y);
  b[x][y] = u;

  for(int dir = 0; dir < 4; dir++) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(OOB(nx, ny)) continue;
    vctcnt[nx][ny]--;
  }
}

void calc() {
  for(int i = 1; i <= n*n; i++) {
    int cnt = 0;
    auto [cx, cy] = ps[i];
    for(int j = 0; j < 4; j++) {
      auto [nx, ny] = ps[pref[i][j]];
      if(abs(nx - cx) + abs(ny - cy) != 1) continue;
      cnt++;
    }
    if(!cnt) continue;
    int a = 1;
    while(--cnt) a *= 10;
    ans += a;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setup();
  for (int i = 1; i <= n*n; i++) {
    init();
    setprefer();
    setseat();
  }
  calc();
  cout << ans;
}
/*
setup 함수(26-37번째 줄)
- 인원들의 위치를 ps 배열에 미정 상태(-1, -1)로 설정
- 인접한 칸 중에서 비어있는 칸을 세서 vctcnt에 기록

init 함수(39-44번째 줄)
- 자리별 점수를 기록하는 score 배열 초기화
- 점수 중 최댓값을 기록하는 mx에 0 할당
- 비어있는 칸의 수와 행 번호, 열 번호를 받아 자리 후보를 기록하는 cand 벡터 초기화

setprefer 함수(46-61번째 줄)
- 이번 좌석 배정의 대상이 되는 학생 번호, u를 입력 받음(47번째 줄)
- 좋아하는 친구 목록을 기록하면서 좋아하는 친구가 있는 자리를 확인
- 좋아하는 친구가 아직 자리를 정하지 못한 경우(52번째 줄) 다음 좋아하는 친구를 확인
- 좋아하는 친구가 자리에 앉아 있는 경우, 그 친구가 인접한 빈자리들에 점수를 추가
- 점수 최댓값을 mx에 갱신

setseat 함수(63-81번째 줄)
- 좋아하는 학생이 가장 많은 칸들을 cand에 기록
- cand에는 비어있는 칸 수를 센 vcnt와 행 번호 x, 열 번호 y를 (-vcnt, x, y)로 삽입한다.
- cand를 정렬하면 vcnt가 내림차순으로 정렬되고,
  행 번호의 오름차순, 열 번호의 오름차순으로 각각 정렬 우선 순위가 낮아진다.
  따라서 이렇게 정렬된 가장 첫번째 원소인 cand[0]를 꺼내 b[x][y]에 좌석 배정의 대상이 되는 학생 번호를 기록

calc 함수
- 모든 학생의 자리 배정이 끝난 후 학생들의 인접한 위치에 있는 좋아하는 친구 수를 세고,
  학생 수에 따라 점수를 계산하여 총 만족도를 기록하는 ans 변수에 더함

이후 ans 값을 답으로 출력한다.
*/