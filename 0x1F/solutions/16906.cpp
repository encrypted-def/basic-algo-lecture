// Authored by : Joshua-Shin
// Co-authored by : -
// http://boj.kr/e98d872814c54797b4f8a2bb47632e3f
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int nxt[MX][2], root = 1, unused = 2, n;
bool chk[MX], success;
vector<pair<int, int>> v;
map<int, string> m; // 입력받은 수의 인덱스와 입력받은 수로 만든 문자열
string successStr;
int c2i(char c) {
  return c - '0';
}
void initiate() {
  for (int i = 0; i < 1000; i++) {
    nxt[i][0] = -1;
    nxt[i][1] = -1;
  }
}
void insert(string &s) {
  int cur = root;
  for (auto c : s) {
    if (nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = true;
}
bool find(string &s) {
  int cur = root;
  for (auto c : s) {
    if (nxt[cur][c2i(c)] == -1)
        return false;
    cur = nxt[cur][c2i(c)];
  }
  return chk[cur];
}
void dfs(int len, string s) {
  if (success) return;
  if (s.size() == len) {
    insert(s);
    success = true;
    successStr = s;
  }
  string s2 = s + '0';
  if (!find(s2)) dfs(len, s2);
  if (success) return;
  string s3 = s + '1';
  if (!find(s3)) dfs(len, s3);
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  initiate();
  for (int i = 0; i < n; i++) {
    int len;
    cin >> len;
    v.push_back({len, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    auto [len, idx] = v[i];
    success = false;
    dfs(len, "");
    if (!success) {
      cout << -1;
      return 0;
    }
    m[idx] = successStr;
  }
  cout << 1 << '\n';
  for (int i = 0; i < n; i++)
    cout << m[i] << '\n';
}
/*
단어의 길이가 작은 순서대로 dfs 함수에 길이 값을 넣어 트라이에 생성한 문자열을 insert함.
dfs를 돌며 삽입이 가능한 곳이 한 군데라도 존재한다면 바로 함수를 빠져나오고,
단 하나의 문자열이라도 insert에 성공하지 못하면 -1 출력하며 종료.
*/
