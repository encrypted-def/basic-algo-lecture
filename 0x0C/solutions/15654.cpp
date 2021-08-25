// Authored by : OceanShape700
// Co-authored by : -
// http://boj.kr/c1fe6f1bbe3541dfb015d09bc8976a4f
#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[9];
int sel[9];  // 선택한 수를 저장하는 배열
bool vis[9]; // 선택 여부를 확인하는 배열

void bt(int cnt){
  if(cnt == M){
    for(int i = 0; i < M; ++i)
      cout << sel[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i = 0; i < N; ++i){
    if(vis[i]) continue;
    vis[i] = true;
    sel[cnt] = num[i]; // 선택한 수 저장
    bt(cnt+1);
    vis[i] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for(int i = 0; i < N; ++i) cin >> num[i];
  sort(num, num + N); // 입력한 수열을 오름차순으로 정렬
  bt(0);
}
