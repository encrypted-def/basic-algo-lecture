// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/65dc47124e3c4f53a9e5e710e78fa881
#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n;
int state[100005]; 

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
  int cur = x;
  while(true){
    state[cur] = x;
    cur = arr[cur];
    // 이번 방문에서 지나간 학생에 도달했을 경우
    if(state[cur] == x){
      while(state[cur] != CYCLE_IN){
        state[cur] = CYCLE_IN;
        cur = arr[cur];
      }
      return;
    }
    // 이전 방문에서 지나간 학생에 도달했을 경우
    else if(state[cur] != 0) return;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    fill(state+1, state+n+1, 0);
    for(int i = 1; i <= n; i++)
      cin >> arr[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
      if(state[i] == NOT_VISITED) run(i);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
      if(state[i] != CYCLE_IN) cnt++;
    }
    cout << cnt << '\n';
  }
}

/*
블로그 풀이 : https://blog.encrypted.gg/499
유튜브 풀이 : https://youtu.be/yPuow6aACvE
*/
