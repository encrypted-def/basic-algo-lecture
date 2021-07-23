// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/c1c7cd2d6487442f83a3fc8f1267c058

#include <bits/stdc++.h>
using namespace std;
int a[20001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;cin>>T;
  while(T--){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a, a+n);
    int ans = 0;
    for(int i=0;i<m;++i){
      int num;cin>>num;
      int index = upper_bound(a, a+n, num) - a;
      ans += n - index;
    }
    cout<<ans<<'\n';
  }
}
/*
이분탐색을 이용한 풀이
*/
