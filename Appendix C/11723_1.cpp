// http://boj.kr/7c4a1a954b7f4aa19635cf6dcfc5a5c6
#include <bits/stdc++.h>
using namespace std;

int state[20];

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
      state[x-1] = 1;      
    }
    else if(com == "remove"){
      cin >> x;
      state[x-1] = 0;
    }
    else if(com == "check"){
      cin >> x;
      cout << state[x-1] << '\n';
    }
    else if(com == "toggle"){
      cin >> x;
      state[x-1] = 1 ^ state[x-1];
    }
    else if(com == "all"){
      fill(state, state+20, 1);
    }
    else{ // empty
      fill(state, state+20, 0);
    }
  }
}
