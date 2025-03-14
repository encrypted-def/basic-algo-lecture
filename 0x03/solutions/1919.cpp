// Authored by : twinkite
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/ae5d8d2f69f04530b4df0c591e9b07d5
#include <bits/stdc++.h>
using namespace std;

int arr[2][26], res;
string s1, s2;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>s1>>s2;
  for(char c : s1)
    arr[0][c-'a']++;
  
  for(char c : s2)
    arr[1][c-'a']++;
  
  for(int i=0; i<26; i++)
    res += abs(arr[0][i]-arr[1][i]);
  
  cout << res;
}
