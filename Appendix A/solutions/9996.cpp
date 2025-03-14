// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/c8b3b907ac6d402f88270d7de04349ba
#include <bits/stdc++.h>
using namespace std;

string sep = "*", p, f;
vector<string> ss;

vector<string> split(string& s, string& sep) {
  vector<string> ret;
  int pos = 0;
  while(pos < s.size()) {
    int nxt_pos = s.find(sep, pos);
    if(nxt_pos == -1) nxt_pos = s.size();
    if(nxt_pos - pos > 0)
      ret.push_back(s.substr(pos, nxt_pos - pos));
    pos = nxt_pos + sep.size();
  }
  return ret;
}

bool solve() {
  cin >> f;
  if(f.size() < ss[0].size() + ss[1].size()) return 0;
  if(f.find(ss[0]) != 0) return 0;
  int j = f.size() - ss[1].size();
  for (int i = 0; i < ss[1].size(); i++)
    if(ss[1][i] != f[j++]) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;

  cin >> p;
  ss = split(p, sep);

  while(t--) {
    if(solve()) cout << "DA\n";
    else cout << "NE\n";
  }
}
/*
split 함수는 강의에 수록된 구현을 그대로 가져왔다(10-21번째 줄).

split 함수를 통해 sep = "*"를 분리한다.
별표는 문자열의 시작과 끝에 있지 않다는 조건으로 인해
ss[0]는 파일 이름의 시작 부분에 매칭되는 문자열이 되며,
ss[1]은 파일 이름의 끝 부분에 매칭되는 문자열이 된다.

이후 solve 함수는 아래 조건을 확인한다.
  - 입력 받은 파일 이름은 시작하는 문자열의 길이와 끝맺는 문자열의 길이 합보다 짧으면 안 된다(25번째 줄).
  - 시작하는 문자열이 최초로 발견되는 인덱스는 0이어야 한다(26번째 줄).
  - 이후 끝맺는 문자열 ss[1]을 파일 이름의 끝에 뒀을 때 서로 일치해야 한다(27-29번째 줄).

모든 조건이 충족되면 파일 이름이 패턴과 일치하는 것이므로 참을 반환한다.
충족되지 않는 조건이 있는 경우 거짓을 반환한다.
*/