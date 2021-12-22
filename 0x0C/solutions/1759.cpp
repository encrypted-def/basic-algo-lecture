// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/86e254ac9f8445f4b4aecc027b444f5b
#include <bits/stdc++.h>
using namespace std;

int l, c;
unsigned char arr[17];
unsigned char s[17];
bool isused[17];

void func(int k, int st){
  if(k == l){
    bool flag = false;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < l; i++){
      if(s[arr[i]] == 'a' ||
         s[arr[i]] == 'e' ||
         s[arr[i]] == 'i' ||
         s[arr[i]] == 'o' ||
         s[arr[i]] == 'u') cnt1++;
      else cnt2++;
    }
    if(cnt1 >= 1 && cnt2 >= 2) flag = true;

    if(flag){
      for(int i = 0; i < l; i++)
        cout << s[arr[i]];
      cout << "\n";
    }
  }

  for(int i = st; i < c; i++){
      arr[k] = i;
      func(k+1, i+1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> c;
  for(int i = 0; i < c; i++) cin >> s[i];
  sort(s, s+c);
  func(0, 0);
}
