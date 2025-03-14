// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/ff566430472940f088b7a415ba8f1b8f
#include <bits/stdc++.h>
using namespace std;

string s;

int getcode() {
  if(s[0] == '_' || s[s.size() - 1] == '_') return 0;
  if(isupper(s[0])) return 0;
  bool is_ub = 0, is_upper = 0;
  for (int i = 1; i < s.size(); i++) {
    if(s[i] == '_') {
      if(s[i - 1] == '_') return 0;
      is_ub = 1;
    }
    if(isupper(s[i])) is_upper = 1;
  }
  if(is_ub && is_upper) return 0;
  else if(is_ub) return 1;
  return 2;
}

void ctoj() {
  bool is_nxt_upper = 0;
  for(char c : s) {
    if(c == '_') { is_nxt_upper = 1; continue; }
    if(is_nxt_upper) cout << (char)toupper(c);
    else cout << c;
    is_nxt_upper = 0;
  }
}

void jtoc () {
  for(char c : s) {
    if(isupper(c)) { cout << '_'; }
    cout << (char)tolower(c);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  int code = getcode(); // code = 0: none, 1: cpp, 2: java
  if(!code) cout << "Error!";
  else if(code == 1) ctoj();
  else jtoc();
}
/*
getcode 함수를 통해 문자열을 구성하는 문자를 확인하며
어떤 형식을 따른 변수명인지 구분한다.
이때, 코드는 1의 경우 cpp 형식, 2의 경우 java, 어느 쪽도 아닌 경우 0이다.

언더바는 문자와 문자를 구분한다고 명시되어 있으므로,
연속해서 쓰이거나 변수명의 맨앞과 맨뒤에 쓰일 수 없다(10번째 줄).
또한, 첫 문자가 대문자인 경우는 어느 쪽에도 속하지 않는다(11번째 줄).

이후 언더바와 대문자가 있는지 확인한다.
언더바가 있으면 cpp이고 대문자가 있으면 java이다.
둘 다 있는 경우 어느 쪽에도 속하지 않으니 0을 반환한다.
특별히 언더바가 있는 경우 연속되진 않는지 파악한다(14-17번째 줄).
연속된 언더바가 확인되면 0을 반환한다.

cpp의 경우 ctoj를, java의 경우 jtoc를 호출한다.

cpp는 언더바가 나오면 이를 출력하지 않고,
다음 문자를 대문자로 출력하도록 is_nxt_upper = 1로 갱신한다(28번째 줄).

java는 대문자가 나오면 대문자를 출력하기 전에 언더바를 출력하고,
대문자를 소문자로 바꿔 출력한다(36-39번째 줄).
*/