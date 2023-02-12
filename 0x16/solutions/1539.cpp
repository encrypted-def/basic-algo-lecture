// Authored by : 0000000000
// Co-authored by : -
// http://boj.kr/e3e56a7a9a8844fdb203b3563575ecc5
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h[250005];
set<int> s;
ll res;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  
  int n; cin >> n;
  h[0] = 0; s.insert(0);
  h[n + 1] = 0; s.insert(n + 1);
  
  n--;
  int a; cin >> a; a++;
  h[a] = 1; s.insert(a);
  res = 1;
  
  while (n--) {
    cin >> a; a++;
    auto it = s.lower_bound(a);
    h[a] = max(h[*prev(it)], h[*it]) + 1;
    s.insert(a);
    
    res += h[a];
  }
  
  cout << res;
}

/*
A의 높이를 H[A]라 하면, H[A]는
max(H[(A보다 작은 수들 중 최댓값)], H[(A보다 큰 수들 중 최솟값)]) + 1
이 됩니다.

Set이 비어 있을 때 처리를 편하게 하기 위해 값에 +1을 해 줬습니다.
*/
