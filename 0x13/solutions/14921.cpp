// Authored by : HJPark
// Co-authored by : -
// http://boj.kr/3b73c9a75b7c4d44be56fd6af6fc9fed
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int ans = 1e9 + 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  int st = 0, en = n - 1;
  while (st < en) {
    int val = a[st] + a[en];
    if (abs(val) < abs(ans)) ans = val;
    if (val < 0) st++;
    else en--;
  }

  cout << ans;
}

/*
투포인터를 이용한 풀이
st, en이 입력된 배열의 양 끝을 가르킨다.
a[st]와 a[en]을 혼합한 특성값의 절대값이 ans의 절대값보다 낮을 경우 ans를 갱신한다.
만약 혼합한 특성값이 0보다 작은 경우 st를 1만큼 증가시키고
0보다 큰 경우 en을 1만큼 감소시킨다.
*/
