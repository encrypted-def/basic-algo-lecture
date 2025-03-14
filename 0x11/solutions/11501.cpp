// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/4b28aa2d9ef5448bb63d304f769f0c34
#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;cin>>T;
  while(T--){
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    int max_val = a[n-1];
    long long ans = 0;
    for(int i=n-2;i>=0;--i) {
      if(a[i] > max_val) max_val = a[i];
      ans += max_val - a[i];
    }
    cout<<ans<<'\n';
  }
}
