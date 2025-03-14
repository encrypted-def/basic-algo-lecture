// Authored by : OceanShape
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d0ab2b9645774292a86f9eee2a394171
#include <bits/stdc++.h>
using namespace std;

int n, w, L, ans;
int bridge[101]; // 다리의 칸별 무게(트럭의 무게)를 저장하는 변수
queue<int> truck; // 이동하는 트럭의 목록을 순차적으로 저장하는 변수

// 다리가 비었는지 확인하는 함수
bool isEmpty(){
  for(int i = 0; i<w; ++i)
    if(bridge[i]) return false;
  return true;
}

// 트럭의 이동을 진행하는 함수
void go(){
  for(int i = w-1; i > 0; --i)
    bridge[i] = bridge[i-1];
  bridge[0] = 0;
}

// 다리 위 트럭의 무게를 계산하는 함수
int calculate(){
  int sum = 0;
  for(int i = 0; i<w; ++i)
    sum+=bridge[i];
  return sum;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w >> L;
  while(n--) {
    int i;
    cin >> i;
    truck.push(i); // 출발할 트럭의 목록을 순차적으로 저장
  }

  do{
    int tmp = calculate(); // 현재 다리 위 트럭들의 무게
    if(tmp<=L) {
      tmp-=bridge[w-1]; // 나갈 트럭의 무게를 제외
      go();
      // 추가로 이동할 트럭이 있고, 다리가 무게를 버틸 경우
      if(!truck.empty()&&(tmp+truck.front()<=L)){
        bridge[0]=truck.front(); truck.pop();
      }
    }
    ++ans;
  }while(!isEmpty()); // 모든 트럭이 이동하여 다리가 빌 때까지 반복

  cout << ans;
}
