// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/00547c6365314010a6b896072a7d4ea5
#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> p(10000000, true); // 소수 판정
vector<bool> pl(100000000); // 팰린드롬 판정
int p10[5] = {1, 10, 100, 1000, 10000};

void sieve() {
  p[0] = p[1] = false;
  for (int i = 2; i * i <= 9999999; i++) {
    if (!p[i]) continue;
    for (int j = i * i; j <= 9999999; j += i)
      p[j] = false;
  }
}

int reverse(int n) {
  int ret = 0;
  while (n) {
    ret = ret * 10 + n % 10;
    n /= 10;
  }
  return ret;
}

void palindrome() {
  for (int i = 1; i <= 9999; i++) {
    int sz = to_string(i).size();
    int lo = p10[sz - 1];
    int hi = p10[sz];

    int rev = reverse(i);
    int tail = rev % lo; // n을 뒤집은 수에서 가장 앞에 있는 숫자를 제거한 수

    pl[i * lo + tail] = true;
    pl[i * hi + rev] = true;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  sieve(); palindrome();
  for (int i = n; i <= 9999999; i++) {
    if (p[i] && pl[i]) {
      cout << i;
      return 0;
    }
  }
}
/*
palindrome 함수에서 i = 1234일 때 (i * lo + tail) = 1234321, (i * hi + rev) = 12344321이 된다.

만약 이게 여러 n에 대해 주어진 수를 구하는 문제였다면 지금과 같이 배열을 이용해
미리 계산을 해둘 필요가 있다면 이 문제의 상황에서는 굳이 그럴 필요가 없다.
*/
