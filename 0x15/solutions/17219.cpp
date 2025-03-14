// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/6dbb1711d18a41e48fa54edfcb93cc7c
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  string s, p;
  unordered_map<string, string> umap;

  cin >> N >> M;
  while (N--) {
    cin >> s >> p;
    umap[s] = p;
  }
  while (M--) {
    cin >> s;
    cout << umap[s] << '\n';
  }
}