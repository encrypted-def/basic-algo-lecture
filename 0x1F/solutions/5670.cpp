// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/d335d203808e47d5a4f5f7dbe17ecdfb
#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1, MX = 1e6 + 10;
int unused, keystroke_total;
bool chk[MX];
vector<pair<int, int>> nxt[MX]; // 자식을 동적 배열로 관리

// node의 자손 중, c에 해당하는 자손이 있는지 체크합니다.
int getchild(int node, char c) {
  for (auto [id, c_] : nxt[node])
    if (c == c_) return id;
  return -1;
}
void insert(string& s) {
  int curr = ROOT;
  for (auto c : s) {
    int child = getchild(curr, c);
    if (child == -1) {
      child = unused;
      nxt[curr].push_back({unused++, c});
    }
    curr = child;
  }
  chk[curr] = true;
}
// dfs 탐색
void dfs(int curr, int key_strokes) {
  if (chk[curr])
    keystroke_total += ++key_strokes;
  else if (nxt[curr].size() > 1)
    ++key_strokes;
  for (auto [nxt_node, _] : nxt[curr])
    dfs(nxt_node, key_strokes);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(2);

  int N;
  while (cin >> N) {
    for (int i = 0; i < MX; i++) nxt[i].clear();
    fill(chk, chk + MX, 0);
    unused = ROOT + 1;
    keystroke_total = 0;

    vector<string> words(N);
    for (int i = 0; i < N; i++) cin >> words[i];
    for (auto& s : words) insert(s);
    for (auto [id, _] : nxt[ROOT]) dfs(id, 0);
    cout << 1.0 * keystroke_total / words.size() << '\n';
  }
}
/*
자판을 누르는 행위는 다음과 같은 경우에 이루어집니다.
1. 단어 분기가 존재할 경우
2. 단어가 완성되었을 경우
이 두가지 경우에 맞추어서 적절하게 카운터를 올려주면서
탐색해주면 자판을 누르는 횟수를 계산할 수 있습니다.

유의점: 처음 한 번은 무조건 누르게 되어있으므로,
ROOT의 각 자식에서부터 탐색을 시작해야 합니다.

메모리 절약을 위해 동적 배열로 구현했지만 자식을 26칸 배열로 두어도
아마 통과에는 문제가 없을 것입니다.
*/
