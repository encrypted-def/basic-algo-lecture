// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/a237cd7949004a76aa9ac3cf1b13c03c
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k){ // 현재 k개까지 수를 택했음.
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
    cout << '\n';
    return;
  }
  int st = 1; // 시작지점, k = 0일 때에는 st = 1
  if(k != 0) st = arr[k-1]; // k != 0일 경우 st = arr[k-1]
  for(int i = st; i <= n; i++){
    arr[k] = i; // k번째 수를 i로 정함
    func(k+1); // 다음 수를 정하러 한 단계 더 들어감
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  func(0);
}
