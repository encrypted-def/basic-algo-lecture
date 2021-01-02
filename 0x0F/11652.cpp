// http://boj.kr/f3feaf22016f4c9687b84ab6be2f4389
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  int cnt = 0;
  long long mxval = -(1ll << 62) - 1; // 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생
  int mxcnt = 0;
  for(int i = 0; i < n; i++){
    if(i == 0 || a[i-1] == a[i]) cnt++; // i가 0인 경우 앞쪽 식이 true이기 때문에 a[i-1]을 참조하지 않음
    else{
      if(cnt > mxcnt){
        mxcnt = cnt;
        mxval = a[i-1];
      }
      cnt = 1;
    }
  }
  if(cnt > mxcnt) mxval = a[n-1]; // 제일 마지막 수가 몇 번 등장했는지를 별도로 확인
  cout << mxval;
}
