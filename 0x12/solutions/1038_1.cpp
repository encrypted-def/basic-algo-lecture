// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/33441c53abac4efd85f455173bfef20a
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> nums; 
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  // brute를 2진수로 나타냈을 때의 값을 가지고 임의의 부분집합을 얻어내고, 대응되는 감소하는 수를 nums에 추가
  for(int i = 1; i < 1024; i++){
    int brute = i;
    ll num = 0;
    for(int j = 9; j >= 0; j--){
      if(brute % 2 == 1) num = 10*num + j;
      brute /= 2;
    }
    nums.push_back(num);
  }
  sort(nums.begin(), nums.end());
  int n;
  cin >> n;
  if(n > 1022) cout << -1;
  else cout << nums[n];
}

/*
집합 {0,1,2,...,9}에서 공집합이 아닌 임의의 부분집합을 생각해보자.
예를 들어 {1,3,5,9}라고 할 때 이 집합에 대응되는 감소하는 수는 무조건 1개이다.
(수를 감소하게 둬야하기 때문) 그렇기 때문에 감소하는 수는 2^10 - 1 = 1023개이고
미리 감소하는 수를 다 구한 후 정렬하면 N번째의 수를 편하게 알아낼 수 있다.
*/
