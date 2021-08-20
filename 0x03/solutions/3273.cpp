// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/44ac0b41904946a9a949367142961056
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
  for (int i = 1; i < (x+1)/2; ++i) {
    // 합이 x가 되는 서로 다른 자연수 (i,x-i)가 존재할 경우
    if (a[i]==1 && a[x-i]==1) ans++;
  }
  cout << ans;
}

/*
x가 짝수일 때에는 (x/2 - 1)까지, 홀수일 때에는 (x-1)/2까지 탐색할 수 있도록 하기 위해서
i < (x+1)/2로 뒀음. 직접 x가 10일 때 / 11일 때를 생각해보면 이해 가능
*/
