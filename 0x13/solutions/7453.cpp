// Authored by : scsc3204
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/45af92e52b8a4d24b52494518812dccd
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
int a[4002], b[4002], c[4002], d[4002];
int ab[16000002], cd[16000002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cd[i*n + j] = c[i] + d[j];

  sort(cd, cd + n*n);
  
  ll ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      ans += upper_bound(cd, cd + n*n, -a[i] - b[j]) - lower_bound(cd, cd + n*n, -a[i] - b[j]);

  cout << ans;
}
/*
a[i]+b[j]들을 저장할 ab 배열을 별도로 선언하지 않아도 되지만, 선언해서 정렬한 후 크기 순으로
탐색을 할 경우에는 cache hit이 올라가서 속도가 빨라짐.
코드 : http://boj.kr/8312a3fc055744dab8088197ac57d52a
설명 : https://www.acmicpc.net/board/view/74585
*/
