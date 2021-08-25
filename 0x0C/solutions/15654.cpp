// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/31394e22027f4d4f87affb939d24df91
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

  for(int i = 0; i < n; i++){ // 0부터 n-1까지의 인덱스에 대해
    if(!isused[i]){ // 아직 i가 사용되지 않았으면
      arr[k] = i; // k번째 인덱스를 i로 정함
      isused[i] = 1; // i를 사용되었다고 표시
      func(k+1); // 다음 인덱스를 정하러 한 단계 더 들어감
      isused[i] = 0; // k번째 인덱스를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
    }
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
