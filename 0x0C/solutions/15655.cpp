// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : Kim-AYoung
// http://boj.kr/2cd18796fe364e7c95cd1764d73e15e8
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
int num[10];

void func(int k){ // 현재 k개까지 수를 택했음.
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' '; // arr에 기록해둔 인덱스에 대응되는 수를 출력
    cout << '\n';
    return;
  }
  int st = 0; // 시작지점, k = 0일 때에는 st = 0
  if(k != 0) st = arr[k-1] + 1; // k != 0일 경우 st = arr[k-1]+1
  for(int i = st; i < n; i++){
    arr[k] = i; // k번째 인덱스를 i로 정함
    func(k+1); // 다음 인덱스를 정하러 한 단계 더 들어감
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, num+n); // 수 정렬
  func(0);
}
