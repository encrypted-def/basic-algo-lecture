// Authored by : scsc3204
// Co-authored by : -
// http://boj.kr/8312a3fc055744dab8088197ac57d52a
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
  
  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      ab[cnt] = a[i] + b[j];
      cd[cnt++] = c[i] + d[j];
    }
  
  sort(ab, ab + n*n);
  sort(cd, cd + n*n);
  
  ll ans = 0;
  for(int i = 0; i < n*n; i++)
    ans += upper_bound(cd, cd + n*n, -ab[i]) - lower_bound(cd, cd + n*n, -ab[i]);
  cout << ans;
}