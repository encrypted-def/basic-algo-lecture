// Authored by : hehehHwang
// Co-authored by : -
// http://boj.kr/c1f56e7cb6f743698c0795479b25ea9e
#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int N, M, t;
void solve(vector<int>& seq) {
  // Base case: 수열이 완성이 되었다면, 출력하고 끝냅니다.
  if ((int)seq.size() == M) {
    for (int v : seq) cout << v << " ";
    cout << '\n';
    return;
  }
  for (int v : arr) {
    seq.push_back(v);
    solve(seq);
    seq.pop_back();
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  // 숫자가 중복으로 들어올 경우, 한 개씩만 세도록 합니다.
  vector<bool> chk(10002);
  while (N--) {
    cin >> t;
    chk[t] = true;
  }
  for (int i = 1; i <= 10000; i++)
    if (chk[i]) arr.push_back(i);

  vector<int> ans;
  solve(ans);
}