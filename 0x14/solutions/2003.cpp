// Authored by : pjshwa
// Co-authored by : -
// http://boj.kr/b7ec5531223f449f99942515f10fb39b
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll pf_sum[10005];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  pf_sum[0] = 0;
  for (int i = 1; i <= n; i++) cin >> pf_sum[i], pf_sum[i] += pf_sum[i - 1];

  int lp = 0, rp = 0;
  int ans = 0;

  while (rp <= n) {
    ll csum = pf_sum[rp] - pf_sum[lp];
    if (csum <= m) {
      if (csum == m) ans++;
      rp++;
    }
    else lp++;
  }

  cout << ans;
}

/*
구간의 합을 관리할 때 강의 내에서 소개한 방법과 같이 tot 변수를 하나 들고 있어도 되고 이 코드와 같이 prefix sum을 이용해도 됨
*/
