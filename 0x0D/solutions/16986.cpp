// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/4b3dadce244f43a7b29fb726b58953bb
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[11][11];
int p[3][25]; // 지우/경희/민호의 패턴

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < 20; i++) cin >> p[1][i];
  for(int i = 0; i < 20; i++) cin >> p[2][i];
  for(int i = 0; i < n; i++) p[0][i] = i+1;
  do{
    int w[3] = {0,0,0}; // 각 플레이어가 이긴 횟수
    int idx[3] = {0,0,0}; // 이번에 내야하는 손동작
    int c1 = 0, c2 = 1; // 이번에 경기를 하는 사람
    while(1){ // 경기를 진행한다
      if(c1 > c2) swap(c1,c2);
      if(c1 == 0 and idx[0] >= n) // 지우가 n+1번째 경기를 치뤄야하는 상황이면 탈출
        break;
      int hand1 = p[c1][idx[c1]++];
      int hand2 = p[c2][idx[c2]++];
      if(a[hand1][hand2] == 2){ // c1의 승리
        w[c1]++;
        if(w[c1] == k) break;
        c2 = 3-c1-c2;
      }
      else{ // c2의 승리
        w[c2]++;
        if(w[c2] == k) break;
        c1 = 3-c1-c2;
      }
    }
    if(w[0] == k){ // 지우가 k번 이겼으면
      cout << 1;
      return 0;
    }
  }while(next_permutation(p[0],p[0]+n));
  cout << 0;
}
