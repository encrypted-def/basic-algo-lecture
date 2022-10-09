// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/66af541bacd0423aaf71483d4bb38f9c
#include <bits/stdc++.h>
using namespace std;

int d[1005];  // 돌이 i개 있을 때 선공이 이기면 0, 후공이 이기면 1
string ans[] = {"SK", "CY"};
int cand[] = {1, 3, 4};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  fill(d, d + 1005, -1);
  d[1] = 0;
  d[2] = 1;
  d[3] = 0;
  d[4] = 0;

  for (int i = 5; i <= n; i++) {
    for (int j : cand) {
      if (d[i - j] == 1) {
        d[i] = 0; break;
      }
      else d[i] = 1;
    }
  }

  cout << ans[d[n]];
}
/*
상근이가 맨 처음에 j개의 돌을 가져갔을 때 창영이 턴에서 남은 돌의 개수에 대하여
d[i - j](j = 1, 3, 4)가 하나라도 1일 경우 창영이가 선공했을 때 상근이가 이긴다는 뜻이므로
이를 만족하는 j개 만큼 첫 턴에 상근이가 가져가면 무조건 이길 수 있음
그렇지 않을 경우 창영이가 이길 수밖에 없음
*/
