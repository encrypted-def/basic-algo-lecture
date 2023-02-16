// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/9a99a506a8604bf8aa7bf8a9b3960543
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;

string s;
int f[MX + 2];

int try_match(int len) {
  int j = 0, cnt = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] != s[j]) return 0;
    j++;
    if(j == len) { j = 0; cnt++; }
  }
  return cnt;
}

int solve(int len) {
  int ans = 1;
  while(1) {
    len = f[len - 1];
    if(len == 0) break;
    if(s.size() % len != 0) continue;
    int no_of_match = try_match(len);
    ans = max(ans, no_of_match);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  while(s[0] != '.') {
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
      while(j > 0 && s[i] != s[j]) j = f[j - 1];
      if(s[i] == s[j]) f[i] = ++j;
    }
    int n = solve(s.size());
    cout << n << '\n';
    cin >> s;
  }
}
/*
이 문제를 '문자열 s의 부분 문자열 a'와 '문자열 거듭제곱의 지수 n'에 대해서
s = a^n을 만족하는 가장 큰 n값을 구하는 문제라고 정리하자.

메인함수에선 입력 받은 문자열 s에 대한 실패함수 f를 계산한다.

solve함수는 문자열 거듭제곱의 지수 n 중을 계산한다.
먼저 f(|S| - 1)을 매칭하고자 하는 a의 길이, len으로 둔다(25번째 줄).
이는 a^n을 만족하는 부분 문자열 a의 후보 중에서 가장 긴 값이 된다.
이 길이가 0이면 a가 s일 때, n이 1인 경우에만 s = a^n식이 성립한다.

이렇게 얻은 후보에 대한 지수 n은 아래 두 과정을 통해 구한다.
  1. 만약 len으로 문자열 s의 길이를 나눈 나머지가 0이 아니라면
     절대 부분 문자열 a의 길이가 될 수 없으므로, 매칭을 시도하지 않는다.
  2. 나누어 떨어지는 경우 매칭을 try_match 함수(12-20번째 줄)를 통해 수행한다.
     이 함수는 매칭 실패 시 0을, 매칭 성공 시 매칭 횟수를 반환한다.

1, 2번에 실패한 경우 다음 후보를 찾는다.
이전에 실패했던 후보의 길이를 len이라 하면
f(len - 1)은 그 후보에 대해 자기 자신을 제외하고
접두사와 접미사가 일치하는 최대 길이가 되며,
이 역시도 부분 문자열 a가 될 수 있는 후보다.
따라서 len = f(len - 1)로 다시 할당하고(22번째 줄)
위 1, 2번 과정을 거치며 최댓값을 갱신한다.

위 과정은 len = 0이 될 때까지 진행되며,
solve함수는 최종적으로 매칭에 성공한 횟수 n을 반환한다.
*/