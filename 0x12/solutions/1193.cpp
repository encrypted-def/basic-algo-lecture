// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/037f3a0f8454498d8b609d819fd67398
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x; cin >> x;

  int i = 1;
  while (x > i) x -= i++;

  int nume = x;
  int deno = i + 1 - x;
  if (i % 2) swap(nume, deno);
  cout << nume << '/' << deno;
}
