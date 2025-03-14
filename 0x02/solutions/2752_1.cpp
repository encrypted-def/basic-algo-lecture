// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/47ed3d4621a546b28422297d8fb6a7ba
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
}
