// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/53c85e8e8abb4e01967f43e58175f9e3
#include <bits/stdc++.h>
using namespace std;

string str;

bool solve(string s) {
  if (s.size() == 1) return 1;
  int half_len = s.size() / 2;

  for (int i = 0; i <= half_len; i++)
    if (s[i] != s[s.size() - i - 1]) return 0;

  if (!solve(s.substr(0, half_len))) return 0;
  if (!solve(s.substr(s.size() - half_len, half_len))) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  if (solve(str)) cout << "AKARAKA";
  else cout << "IPSELENTI";
}
/*
아카라카 팰린드롬인지 확인하는 solve 함수를 9-19번째 줄과 같이 구현한다.

solve 함수는 3가지를 확인한다.
  1. 13-14번째 줄: 현재 문자열이 팰린드롬인지 확인한다.
  2. half_len 길이의 접두사가 아카라카 팰린드롬인지 확인한다.
  3. half_len 길이의 접미사가 아카라카 팰린드롬인지 확인한다.

위 조건 중 어느 하나라도 거짓인 경우 거짓을 반환한다.
그리고 기저 사례로써, 문자열의 길이가 1일 때는 아카라카 팰린드롬이므로 참을 반환한다.
*/