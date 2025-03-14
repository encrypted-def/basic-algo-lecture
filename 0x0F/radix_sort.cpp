#include <bits/stdc++.h>
using namespace std;

int n = 15;
int arr[1000001] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240};

// 1, 10, 100의 자리에 대해서 진행, 수가 최대 3자리수가 아닐 경우 d를 조절해야 함
int d = 3;
// p10[i] = 10의 i승
int p10[3];

// x의 10^a 자리의 값을 반환하는 함수
int digitNum(int x, int a){
  return (x / p10[a]) % 10;
}

vector<int> l[10];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  p10[0] = 1;
  for(int i = 1; i < d; i++) p10[i] = p10[i-1] * 10;
  
  for(int i = 0; i < d; i++){
    for(int j = 0; j < 10; j++) l[j].clear();
    // 각 수를 list에 대입
    for(int j = 0; j < n; j++)
      l[digitNum(arr[j], i)].push_back(arr[j]);
    // 0번 리스트부터 차례로 다시 arr에 넣어 재배열
    int aidx = 0;
    for(int j = 0; j < 10; j++){
      for(auto x : l[j]) arr[aidx++] = x;
    }
  }
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
