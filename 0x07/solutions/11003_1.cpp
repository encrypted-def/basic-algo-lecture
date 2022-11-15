// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/102f4219c84648288e5aac38a46c9e40
#include <bits/stdc++.h>
using namespace std;

priority_queue <pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int x, idx, cur;
  for(int i = 0; i < n; i++) {
    cin >> x;
    pq.push({x, i});
    tie(cur, idx) = pq.top();
    while(idx < max(0, i - m + 1)) {
      pq.pop();
      tie(cur, idx) = pq.top();
    }
    cout << cur << ' ';
  }
}
/*
우선순위 큐를 이용한 풀이
*/
