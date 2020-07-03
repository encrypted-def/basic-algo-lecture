// http://boj.kr/4e7fe4509a3842598592fe4ed79900c0
#include <bits/stdc++.h>
using namespace std;
bool isused1[40]; // column을 차지하고 있는지
bool isused2[40]; // / 방향 대각선을 차지하고 있는지
bool isused3[40]; // \ 방향 대각선을 차지하고 있는지

int cnt = 0;
int n;
void func(int cur) { // cur번째 row에 말을 배치할 예정임
  if (cur == n) { // N개를 놓는데 성공했다면
    cnt++;
    return;
  }
  for (int i = 0; i < n; i++) { // (cur, i)에 퀸을 놓을 예정
    if (isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) // column이나 대각선 중에 문제가 있다면
      continue;
    isused1[i] = 1;
    isused2[i+cur] = 1;
    isused3[cur-i+n-1] = 1;
    func(cur+1);
    isused1[i] = 0;
    isused2[i+cur] = 0;
    isused3[cur-i+n-1] = 0;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}
