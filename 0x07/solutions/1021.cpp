// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/2a8cd262be0f4b96b6ca2e3b16fe3397
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  deque<int> DQ;
  for (int i = 1; i <= n; i++) DQ.push_back(i);
  int ans = 0;
  while (m--) {
    int t;
    cin >> t;
    int idx = 0;
    while (DQ[idx] != t) idx++;
    while (DQ.front() != t) {
      if (idx < DQ.size() - idx) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
      } else {
        DQ.push_front(DQ.back());
        DQ.pop_back();
      }
      ans++;
    }
    DQ.pop_front();
  }
  cout << ans;
}
