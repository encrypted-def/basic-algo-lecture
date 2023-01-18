// Authored by : Codingding
// Co-authored by : -
// http://boj.kr/8da8cc4eb976414dbfc9423bbf54fa2e
#include <bits/stdc++.h>
using namespace std;

int arr[2][7];

int main(){
  ios::sync_with_stdio(0); 
  cin.tie(0);
	
  int N, K;
  cin >> N >> K;
  int S, Y;
  int ct = 0;
  for(int i = 0; i < N; ++i){
    cin >> S >> Y;
    arr[S][Y]++;
    if(arr[S][Y] == 1) ct++;
    if(arr[S][Y] >= K) arr[S][Y] = 0;
  }
	
  cout << ct << '\n';
	
  return 0;
}
