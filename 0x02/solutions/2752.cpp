// Authored by : twinkite
// Co-authored by : -
// http://boj.kr/e1c98eb9700742e2bacb8db5545002de
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[4];
  for(int i=0;i<3;i++){
      cin>>arr[i];
  }
  sort(arr, arr+3);
  for(int i=0;i<3;i++){
      cout<<arr[i]<<" ";
  }

  return 0;
}