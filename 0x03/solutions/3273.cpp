// Authored by : OceanShape
// Co-authored by : -
// http://boj.kr/1de61c141eca477e8cfe37a0c389fc48
#include <bits/stdc++.h>
using namespace std;

// 각 자연수의 존재 여부를 저장하는 배열
int a[1000001]={};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, t, x, ans=0;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> t;
    a[t]++;
  }

  cin >> x;
  for (int i=1; i<=1000000 && x-i>0; ++i) {
    // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
    if (i!=x-i && a[i]==1 && a[x-i]==1) {
      --a[i];--a[x-i];  // 쌍을 두 번 만들지 않도록 지워준다
      ++ans;
    }
  }
  cout << ans;
}
