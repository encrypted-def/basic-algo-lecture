// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/0a669ebf1000436b94e3067bdda26575
#include <bits/stdc++.h>
using namespace std;

int fibo[42][2];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fibo[0][0] = 1;
  fibo[1][1] = 1;
  for (int i = 2; i <= 40; i++) {
    fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
    fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
  }
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    cout << fibo[N][0] << " " << fibo[N][1] << endl;
  }
}
/*
1. 테이블 정하기
fibo[i][k] = 숫자 i가 k(0 or 1)를 호출한 횟수
2. 점화식 찾기
fibo[i][k] = fibo[i - 1][k] + fibo[i - 2][k]
3. 초기값 정하기
fibo[0][0] = 1, fibo[1][1] = 1
*/