// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : OceanShape
// http://boj.kr/8b89557fe3194aaaba7cbf68ad02e7f7
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[10]={}, ans=1;
  cin >> n;
  // 각 자릿수를 숫자 배열에 저장
  for (int i=n; i>0; i/=10) a[i%10]++;
  // 6과 9는 맞바꿀 수 있으므로, 평균을 사용해 배분
  int tmp = a[6]+a[9];
  a[6]=tmp/2;a[9]=tmp/2;
  // 합이 홀수일 경우
  // 정수형에서 평균을 구하면 1이 사라지므로 더해줌
  if ((tmp/2)*2 != tmp) a[6]++;
  // 가장 큰 값이 최소한으로 필요한 카드 세트 수
  for (int i : a) ans = max(ans, i);
  cout << ans;
}