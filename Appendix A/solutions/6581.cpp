// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/2c0965b7927540c1b66d4a1c08ae672a
#include <bits/stdc++.h>
using namespace std;

const int LIM = 80;

string s, input; 
vector<string> split_input;

vector<string> split(string& s, string sep) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.size()) {
    int nxt_pos = s.find(sep, pos);
    if (nxt_pos == -1) nxt_pos = s.size();
    if (nxt_pos - pos > 0)
      ret.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (getline(cin, s)) input += " " + s;
  for (char& c : input)
    if (c == '\t') c = ' ';

  split_input = split(input, " ");

  int cnt = 0;
  for (auto& str : split_input) {
    if (str != "<br>" && str != "<hr>") {
      if (cnt + str.size() + 1 > LIM) { cout << '\n'; cnt = 0; }
      if (cnt != 0) { cout << ' '; cnt++; }
      cout << str; cnt += str.size();
    } else {
      if (str == "<hr>") {
        if (cnt) cout << '\n';
        int no = LIM;
        while (no--) cout << '-';
      }
      cout << '\n'; cnt = 0;
    }
  }
}
/*
getline으로 문자열을 한 줄씩 입력을 받으며
공백문자로 구분해 input 문자열에 추가한다(29번째 줄).

여러 개의 탭 문자 또한 입력으로 들어오기 때문에, 
이는 공백 문자로 대체해준다(30-31번째 줄).

split 함수를 통해 공백 문자가 제거된
문자열 벡터 split_input을 반환 받는다(33번째 줄).

이후 cnt 변수로 한 줄에 출력된 단어 개수를 카운트한다.
split_input의 원소 str이 <br>이나 <hr>이 아니라면
단어이므로, 아래와 같은 로직을 따라 출력한다.
  - 단어 개수 제한 80자를 넘으면 줄을 바꾸고 cnt를 초기화한다.
  - cnt가 초기화되지 않은 경우, 공백을 출력하고 cnt를 1 증가시킨다.
  - 단어를 출력하고, 출력한 단어의 길이만큼 cnt 값을 증가시킨다.

만약 <br>이나 <hr>인 경우 아래와 같은 로직을 따라 출력한다.
  - 공통: 줄을 바꾸고 cnt를 초기화한다.
  - <hr>: 현위치가 줄의 시작점이 아닌 경우(cnt가 0이 아닌 경우)
    줄을 바꾸고 80개 '-'를 출력한다. 만약, 줄의 시작점이라면 줄을
    바꾸지 않고 80개 '-'를 출력한다.

특별히, 줄바꿈하기 직전 단어 뒤로 공백 문자가 붙으면 오답처리되므로
단어와 단어를 구분할 때만 공백 문자를 출력하도록 하자.
오답 참고: http://boj.kr/dc2fa1e59f6348eea5ad5b81810570ef
*/