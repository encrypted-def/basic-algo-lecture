// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/54ced2c7e27e40da93c95a150d93d56e
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[15];
int num[15];
bool isused[15];

void func(int k){
  if(k == 6){
    bool flag = true;
    int tmp = -1;
    for(int i = 0; i < 6; i++){
      if(tmp > num[arr[i]]) flag = false;
      tmp = num[arr[i]];
    }

    if(flag){
      for(int i = 0; i < 6; i++)
        cout << num[arr[i]] << " ";
      cout << "\n";
    }
    return;
  }
  for(int i = 0; i < n; i++){
    if(!isused[i]){
      arr[k] = i;
      isused[i] = 1;
      func(k+1);
      isused[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++)
      cin >> num[i];
    sort(num, num+n);
    func(0);
    cout << "\n";
    fill(num, num+n, 0);
    fill(arr, arr+n, 0);
  }
}
