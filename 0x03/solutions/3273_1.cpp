// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/2c0c9a326c174019bdaca18ea29b2be8
#include <bits/stdc++.h>
using namespace std;

// 각 자연수의 존재 여부를 저장하는 배열, 배열의 크기를 200만으로 두어
// 25번째 줄에서 x-i의 범위를 별도로 체크하지 않아도 되게끔 했다.
int a[2000001]={};

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
  for (int i = 1; i < (x+1)/2; ++i) {
    // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
    if (a[i]==1 && a[x-i]==1) ans++;
  }
  cout << ans;
}

/*
x가 짝수일 때에는 (x/2 - 1)까지, 홀수일 때에는 (x-1)/2까지 탐색할 수 있도록 하기 위해서
i < (x+1)/2로 뒀음. 직접 x가 10일 때 / 11일 때를 생각해보면 이해 가능
이 코드는 O(n+x)에 동작, x가 최대 200만이므로 통과에는 문제가 없으나 O(n)에 비해서는 느림.
*/
