// Authored by : hehehHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/6cbf128678584f43997ee80f12913aa3
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int k){ // 현재 k개까지 수를 택했음.
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' '; // arr에 기록해둔 인덱스를 참고해 값을 출력
    cout << '\n';
    return;
  }
  for(int i = 0; i < n; i++){ 
    arr[k] = i; // k번째 수를 i로 정함
    func(k+1); // 다음 수를 정하러 한 단계 더 들어감
  }
}

vector<bool> chk(10002);

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int idx = 0; // 수를 삽입할 인덱스. 중복된 수는 제거할 예정.
  while(n--){
    cin >> num[idx];
    if(chk[num[idx]]) continue; // 이미 이전에 수가 들어온 경우 넘어감
    chk[num[idx]] = true; // 그렇지 않은 경우 수를 num 배열에 추가
    idx++;
  }
  // 현재 num에는 중복되지 않은 수들만 들어가있고 길이는 idx.
  n = idx; // 이전 문제들과 비슷한 표현을 사용하기 위해 n = idx로 둠.
  sort(num, num+n);
  func(0);
}
