// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/2385b7f2a4da406f921ee64603eba658
#include <bits/stdc++.h>
using namespace std;

vector<bool> seive(10002, true);
vector<int> primes;
vector<int> adj[10002];
int pwr(int n) {
  int r = 1;
  for (int i = 0; i < n; i++) r *= 10;
  return r;
}
int vec2num(vector<int> &vec) {
  int r = 0;
  for (int i = 0; i < 4; i++) r += vec[i] * pwr(i);
  return r;
}
vector<int> num2vec(int num){
  vector<int> rtn;
  do rtn.push_back(num % 10);
  while (num /= 10);
  return rtn;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  seive[1] = false;
  for (int i = 2; i * i < 10000; i++)
    for (int j = i * i; j < 10000; j += i) seive[j] = false;
  for (int i = 1000; i < 10000; i++)
    if (seive[i]) primes.push_back(i);

  for (int p : primes) { // p == 1279
    vector<int> num = num2vec(p); // num == {9, 7, 2, 1}
    for (int i = 0; i < 4; i++) {
      int t = num[i];
      for (int j = num[i] + 1; j < 10; j++) {
        num[i] = j;
        int changed = vec2num(num);
        if (seive[changed]) {
          adj[p].push_back(changed);
          adj[changed].push_back(p);
        }
      }
      num[i] = t;
    }
  }
  int tc, s, e;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cin >> s >> e;
    queue<pair<int, int>> Q = {};
    vector<bool> vis(10002, 0);
    Q.push({s, 0});
    while (1) {
      if (Q.empty()) {
        cout << "Impossible" << '\n';
        break;
      }
      int num, cnt;
      tie(num, cnt) = Q.front();
      Q.pop();
      if (num == e) {
        cout << cnt << '\n';
        break;
      }
      for (int v : adj[num]) {
        if (vis[v]) continue;
        Q.push({v, cnt + 1});
        vis[v] = true;
      }
    }
  }
}