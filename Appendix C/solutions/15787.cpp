// Authored by : uhwan0723
// Co-authored by : -
// http://boj.kr/213d52a2b98146ccba8b80a28d3f2811
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<int> v(n, 0);
  while(m--){
    int com, i, x;
    // 0-index로 쓰기 위해 i는 i-1로, x는 x-1로 사용합니다.
    cin >> com >> i;
    if(com == 1){
      cin >> x;
      v[i-1] |= (1 << (x-1));
    }
    else if(com == 2){
      cin >> x;
      v[i-1] &= ~(1 << (x-1));
    }
    else if(com == 3)
      v[i-1] = (v[i-1] << 1) & ((1 << 20) - 1);
    else
      v[i-1] = v[i-1] >> 1;
  }
  sort(v.begin(), v.end());
  cout << distance(v.begin(), unique(v.begin(), v.end()));
}
