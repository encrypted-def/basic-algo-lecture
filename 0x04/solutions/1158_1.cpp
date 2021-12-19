// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/4ef85f8d8d834deb8b8ae054d249fff9
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  queue<int> Q;
  for (int i = 1; i <= n; i++) Q.push(i);
  cout << '<';
  while (!Q.empty()) {
    for (int i = 0; i < k - 1; i++) {
      Q.push(Q.front());
      Q.pop();
    }
    cout << Q.front();
    Q.pop();
    if (Q.size()) cout << ", ";
  }
  cout << '>';
}

/*
STL queue를 이용한 풀이
*/
