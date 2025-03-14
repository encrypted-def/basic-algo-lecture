// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/9151aa206208424c9a783d28c77b0f2e
#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int n, k, cnt;
int a[MX*2 + 2];
bool is_bot[MX + 2];

void rot() {
  rotate(a, a + 2*n - 1, a + 2*n);
  rotate(is_bot, is_bot + n - 1, is_bot + n);
  is_bot[n - 1] = 0;
}

void move() {
  for(int cur = n - 2; cur > 0; cur--) {
    int nxt = cur + 1;
    if(!is_bot[cur] || is_bot[nxt]) continue;
    if(a[nxt] == 0) continue;
    if(--a[nxt] == 0) cnt++;
    is_bot[cur] = 0; is_bot[nxt] = 1;
  }
  is_bot[n - 1] = 0;
}

void put_bot() {
  if(a[0] == 0) return;
  if(--a[0] == 0) cnt++;
  is_bot[0] = 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < 2 * n; i++)
    cin >> a[i];

  int t = 0;
  while(++t) {
    rot();
    move();
    put_bot();
    if(cnt >= k) break;
  }
  cout << t;
}
/*
문제 지문은 1-indexed를 따르지만, 풀이는 편의상 0-indexed로 구현했다.
따라서 내리는 위치는 n - 1번 인덱스가 되며, 올리는 위치는 0번 인덱스가 된다.

a는 내구도, is_bot은 해당 인덱스에 로봇 존재 유무를 저장한다.
cnt에는 내구도가 0인 발판 수를 기록한다.
t는 현 단계가 몇 번째 단계인지 기록한다.

rot 함수는 a와 is_bot을 rotate로 옮긴다.
조건에 따라서 내리는 위치에 로봇이 간 경우 이를 제거한다(16번째 줄).

move 함수는 n - 2번 인덱스부터 cur로 지정하고, 순차적으로 값을 감소시키며 확인한다.
nxt는 cur보다 하나 큰 인덱스이며,
cur에는 로봇이 위치하고, nxt에는 로봇이 없는 경우,
그리고 옮길 발판의 내구도가 0이 아닌 경우에만
옮길 수 있으므로, 이를 22-23번째 줄과 같이 구현한다.
로봇을 옮기면서 그 발판의 내구도가 0이 되는 경우에는 cnt를 하나 증가시킨다.
move가 끝난 시점에 내리는 위치에 로봇이 있다면 제거해준다.

이후 올리는 위치에서 로봇 배치를 시도한다.
발판의 내구도가 0이라면 넘어간다.
그렇지 않은 경우 로봇을 올리는데,
이 로봇을 올리면서 발판 내구도가 0이 된다면 cnt를 하나 증가시킨다.

최종적으로 이 작업들을 하면서
내구도가 0인 발판의 수가 k 이상이 되었다면 while 문을 깨고
몇 번째 단계에서 종료되었는지 출력한다.
*/