// Authored by : HJPark
// Co-authored by : -
// http://boj.kr/be49a9e53776483988fd1dd46534d1f3
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int ret[1000005];
int ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  ret[0] = a[0];

  for (int i = 0; i < n; i++) {
    if (ret[ans] < a[i]) {
      ret[ans + 1] = a[i];
      ans++;
    } 
    else {
      int idx = lower_bound(ret, ret + ans, a[i]) - ret;
      ret[idx] = a[i];
    }
  }

  cout << ans + 1;
}

/*
ret에 수열 A의 첫번째를 담습니다.
만약 ret의 마지막보다 a[i]가 크다면 ret의 끝에 a[i]에 추가합니다.
그렇지 않다면, lower_bound()로 a[i]보다 크거나 같은 인덱스를 반환 받고 ret[idx]를 a[i]로 교체합니다.
ans는 인덱싱 때문에 0을 사용했기 때문에 길이는 ans + 1 입니다.
ret가 항상 정확한 가장 긴 증가하는 부분수열을 담지는 않습니다.
*/
