// Authored by : sukam09
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a75486aadfc04beeb40786a0728ffc78
#include <bits/stdc++.h>
using namespace std;

int n;
int a[25][25];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];

  vector<int> team(n);
  fill(team.begin() + n / 2, team.end(), 1);
  int ans = 0x7f7f7f7f;
  // team = {0, 0, 0, .., 0, 1, 1, .. ,1}, team[i]는 i번째 선수의 팀을 의미
  do {
    int diff = 0; // 능력치의 차이
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++){
        if(team[i] != team[j]) continue;
        if(team[i] == 0) diff += (a[i][j] + a[j][i]);
        else diff -= (a[i][j] + a[j][i]);
      }
    }
    ans = min(ans, abs(diff));    
  } while (next_permutation(team.begin(), team.end()));
  cout << ans;
}
