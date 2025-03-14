// Authored by : sukam09
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/f3ac816bd3b44b69baddacb66eaba2f9
#include <bits/stdc++.h>
using namespace std;

int dices[10];
vector<int> locs(4);
int scores[33] = {
  0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
  22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13,
  16, 19, 25, 30, 35, 22, 24, 28, 27, 26, 0
};
int special[33];  // 특수 칸일 경우 파란색 화살표가 가리키는 칸
int nxt[32];  // 빨간색 화살표가 가리키는 칸
int ans;

// idx번째 수를 처리, 현재 점수는 tot
void sim(int idx, int tot) {
  if (idx == 10) {
    if (tot > ans) ans = tot;
    return;
  }

  int dice = dices[idx];
  // i번째 말을 선택
  for (int i = 0; i < 4; i++) {
    int loc = locs[i];
    
    // 선택한 말이 도착 칸일 경우 다른 말을 선택
    if (loc == 32) continue;

    for (int j = 0; j < dice; j++) {
      // 도착 칸일 경우 더 이상 움직이지 않음
      if (loc == 32) break;
      // 말을 처음으로 움직이고 특수 칸일 경우 파란색 화살표를 따라감
      if (j == 0 && special[loc]) loc = special[loc];
      else loc = nxt[loc];
    }

    // 이동할 칸이 도착 칸이 아니고 이미 말이 있으면 다른 말을 선택
    if (loc != 32 && find(locs.begin(), locs.end(), loc) != locs.end()) continue;
    
    int tmp = locs[i];
    locs[i] = loc;
    sim(idx + 1, tot + scores[loc]);
    locs[i] = tmp;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 10; i++) cin >> dices[i];
  
  special[5] = 21;
  special[10] = 27;
  special[15] = 29;
  
  for (int i = 0; i < 32; i++) nxt[i] = i + 1;
  nxt[20] = 32;
  nxt[26] = 20;
  nxt[28] = 24;
  nxt[31] = 24;

  sim(0, 0);
  cout << ans;
}
/*
윷놀이판에 다음과 같이 번호를 붙인다. 시작 칸은 0, 도착 칸은 32로 정의한다.
파란색 화살표가 있는 5, 10, 15번 칸은 특수 칸으로 정의한다.
0          32
1          20 19
2                18
3          26       17
4          25          16
5 21 22 23 24 31 30 29    15
  6        28          14
    7      27       13
      8          12
        9     11
           10
*/
