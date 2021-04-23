// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/463f7849219d4db6a9740a40f381cbfb
#include <bits/stdc++.h>
using namespace std;
int a[101];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;cin>>n;
  for(int i=0;i<n;++i) cin>>a[i];
  int prev = a[n-1];
  int ans = 0;
  for(int i=n-2;i>=0;--i) {
    if(a[i]>= prev) {
      ans += a[i] - prev + 1;
      a[i] = prev - 1;
    }
    prev = a[i];
  }
  cout<<ans;
}
