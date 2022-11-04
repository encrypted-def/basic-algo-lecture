// Authored by : sukam09
// Co-authored by : -
// http://boj.kr/b560da82347a411682f1f3cc7a96d72f
#include <bits/stdc++.h>
using namespace std;

const int MX = 100000 * 10 + 5;
const int ROOT = 1;
int nxt[MX][26];
int unused = 2;
unordered_map<string, int> x;  // 해당 닉네임으로 가입한 유저의 수

int c2i(char c) {
  return c - 'a';
}

void insert(string& s) {
  int cur = ROOT;
  for (auto c : s) {
    if (nxt[cur][c2i(c)] == 0)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
}

string find(string& s) {
  int cur = ROOT;
  string alias = "";
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    alias += c;
    if (nxt[cur][c2i(c)] == 0) return alias;
    cur = nxt[cur][c2i(c)];
  }
  // 마지막 글자까지 트라이에 존재한다면 닉네임+가입한 수가 별칭(단, 1은 생략)
  if (x[s] > 1) alias += to_string(x[s]);
  return alias;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    x[s]++;
    cout << find(s) << '\n';
    insert(s);
  }
}
/*
유저가 가입하기 전 별칭을 찾고 별칭을 찾은 후에 가입함. 단, 그 전에 가입한 유저 수는 늘려야 find 함수에서 제대로 된 값을 받아올 수 있음.
별칭을 찾을 때 alias에 s를 한글자씩 붙여 나가다가 마지막 글자가 트라이에 존재하지 않으면 이것이 별칭이 됨.
*/