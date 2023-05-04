// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/0c17f08c5c2b4ae5a722a344eec6eb25
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
string s;

void eraseChars() {
  cin >> s;
  int pos = 0, nxt_pos = 0;
  while(1) {
    while(s[nxt_pos] >= 'a' && s[nxt_pos] <= 'z')
      nxt_pos++;
    pos = nxt_pos;
    if(pos >= s.length()) break;
    while(s[nxt_pos] >= '0' && s[nxt_pos] <= '9')
      nxt_pos++;
    ans.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos;
  }
}

void eraseZeros() {
  for(string& s : ans) {
    int pos = 0;
    while(s[pos] == '0') pos++;
    string ss = s.substr(pos, s.length() - pos);
    if(ss == "") ss = "0";
    s = ss;
  }
}

bool cmp(string& a, string &b) {
  if(a.length() == b.length()) return a < b;
  return a.length() < b.length();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) eraseChars();
  eraseZeros();

  sort(ans.begin(), ans.end(), cmp);
  for(string s : ans) cout << s << '\n';
}
/*
eraseChars 함수를 정의하여 문자열 내 
14-15번째 줄과 같이 알파뱃 소문자인 경우 인덱스를 증가시킨다.
이 과정이 끝나면 nxt_pos는 숫자를 가리키고 있거나 s.length()에 도달한다.
pos = nxt_pos로 선언한 뒤, pos가 s.length()라면 while문을 깬다.
그렇지 않은 경우 숫자를 가리키고 있는 것이므로,
가리키고 있는 문자가 숫자인 동안 인덱스를 증가시킨다(18-19번째 줄).
이후 substr 멤버함수를 통해 숫자로 이루어진 문자열을 추출한다.

이렇게 추출된 숫자로 구성된 문자열은 0이 앞에 있을 수 있다.
이는 eraseZeros 함수를 통해 삭제한다.
만약 0으로만 이루어진 문자열인 경우 0을 지우는 과정에서
29번째 줄에 빈 문자열이 구성될 것이므로,
"0" 문자열을 할당해준다.

각 줄이 최대 100글자이기 때문에 stoll으로 간단히 풀 수 없다.
따라서, cmp 함수를 35-38번째 줄과 같이 정의해서 ans를 정렬한다.
이후 이같이 정렬된 결과를 답으로 출력한다.
*/