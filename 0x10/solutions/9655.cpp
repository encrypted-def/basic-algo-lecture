// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/4d323fbd173e42989008bafd8e62f5df
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  cout << (n % 2 ? "SK" : "CY");
  /*
  홀수 + 홀수 = 짝수, 짝수 + 홀수 = 홀수이므로 가져간 돌의 총 합이 n이 됐을 때 게임을 이긴다고 하면
  돌을 몇 개를 가져가든 n이 홀수일 때는 상근이, 짝수일 때는 창영이가 무조건 이김을 알 수 있다.
  */
}