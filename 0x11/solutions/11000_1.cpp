// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/422c1bde5a5b422082829cd06a7565a1

#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> lecture[200'002];
priority_queue<int, vector<int>, greater<>> pQ;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    lecture[i] = {a, b};
  }
  pQ.push(0);
  sort(lecture, lecture + N);
  for (int i = 0; i < N; i++) {
    int s, e, c = pQ.top();
    tie(s, e) = lecture[i];
    pQ.pop();
    if (s < c) pQ.push(c);
    pQ.push(e);
  }
  cout << pQ.size();
}

/*
우선순위 큐를 이용한 풀이
*/
