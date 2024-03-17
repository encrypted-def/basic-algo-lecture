// http://boj.kr/1febea8e97bb4493925075f36d6efb8d
#include <bits/stdc++.h>
using namespace std;

int chk[20];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> m;
  while(m--){
    string com;
    int x;
    cin >> com;
    if(com == "add"){
      cin >> x;
      chk[x-1] = 1;      
    }
    else if(com == "remove"){
      cin >> x;
      chk[x-1] = 0;
    }
    else if(com == "check"){
      cin >> x;
      cout << chk[x-1] << '\n';
    }
    else if(com == "toggle"){
      cin >> x;
      chk[x-1] = 1 ^ chk[x-1];
    }
    else if(com == "all"){
      fill(chk, chk+20, 1);
    }
    else{ // empty
      fill(chk, chk+20, 0);
    }
  }
}
