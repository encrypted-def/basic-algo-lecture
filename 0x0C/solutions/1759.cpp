// Authored by : yongjunleeme
// Co-authored by : -
// http://boj.kr/04b7346a15bd441fb7c815c008682893
#include <bits/stdc++.h>
using namespace std;

int l, c;
int arr[17];
char s[17];
bool isused[17];

bool aeiou(char t){
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void func(int k, int st){
  if(k == l){
    bool flag = false;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < l; i++){
      if(aeiou(s[arr[i]])) cnt1++;
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
