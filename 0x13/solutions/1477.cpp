// Authored by : seungmin1217
// Co-authored by : -
// http://boj.kr/9a726bf84a10402b850eefd2d9588f16
#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int v[51];

bool solve(int x){
  // 추가로 필요한 최소한의 휴게소 개수
  int must_cnt = 0;
  int pre = 0;
  for (int i = 0; i <= n; i++) {
    int dist = v[i] - pre;

    if (dist >= x) {
    // 빈 구간 : 7, 구간 최댓값 2 일때 필요한 휴게소 개수는 7/2 = 3개
      if (dist % x != 0)
        must_cnt += dist / x;
      // 빈 구간 : 8, 구간 최댓값 2 일때 필요한 휴게소 개수는 8/2 - 1 = 3개
      else
        must_cnt += (dist / x - 1);
    }
    pre = v[i];
  }
  // 휴게소 개수가 m보다 크다면, 구간 최댓값은 커져야함 (휴게소 개수 감소)
  if (must_cnt > m) 
    return true;
  // 휴게소 개수가 m보다 같거나 작다면, 구간 최댓값은 작아져도 됨 (휴게소 개수 증가 가능)
  // 위 for문에서 dist >= mid를 한번도 만족하지 못한 경우(must_cnt == 0), 구간 최댓값은 작아져야 함
  else 
    return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> l;

  for (int i = 0; i < n; i++)
    cin >> v[i];

  sort(v, v + n);
  // (마지막 휴게소 ~ 도로 끝) 계산을 위해 l(엘)을 삽입
  v[n] = l;
  
  int st = 1, en = l;
  while(st < en){
    int mid = (st + en) / 2;
    if(solve(mid)) st = mid + 1;
    else en = mid;
  }
  
  cout << st;

  return 0;
}
