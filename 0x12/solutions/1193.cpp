// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/4786afbccbb148098938f248823abd35
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin >> x;

  // x에서 1 2 3 ...을 빼다보면 찾는 수가 i 번째 군의 x 번째 수가 된다.
  int i = 1;
  while (x > i) {
    x -= i;
    i++;
  }

  int nume = x;
  int deno = i + 1 - x;
  if (i % 2) swap(nume, deno);  // 홀수 번째 군의 순서가 문제와 반대이므로 뒤집는다.
  cout << nume << '/' << deno;
}
/*
수열을 (1/1) (1/2 2/1) (1/3 2/2 3/1) ... 과 같이 묶으면 i번째 군의 개수는
i개 이고 분자와 분모의 합이 i + 1로 일정함을 알 수 있다.
*/
