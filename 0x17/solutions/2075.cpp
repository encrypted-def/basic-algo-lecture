// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/45e1c40b488544b89ca5d9c966a6cdc0
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, num;
  priority_queue<int, vector<int>, greater<>> pq;
  cin >> N;
  for (int i = 0; i < N * N; i++) {
    cin >> num;
    pq.push(num);
    if (N < (int)pq.size()) pq.pop();
  }
  cout << pq.top() << '\n';
}

/*
문제의 메모리 제한을 고려해 우선순위 큐에 상위 N개의 값만 가지고 있는다.
*/
