// http://boj.kr/bfa34c5aa15d49e1878dc3e79cc0facb
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head, tail;

void push(int x){
  dat[tail++] = x;
}

void pop(){
  head++;
}

int front(){
  return dat[head];
}

int back(){
  return dat[tail-1];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--){
    string q;
    cin >> q;
    if(q=="push"){
      int val;
      cin >> val;
      push(val);
    }
    else if(q=="pop"){
      if(tail==head) cout << -1 << '\n';
      else{
        cout << front() << '\n';
        pop();
      }
    }
    else if(q=="size"){
      cout << tail-head << '\n';
    }
    else if(q=="empty"){
      cout << (tail==head) << '\n';
    }    
    else if(q=="front"){
      if(tail==head) cout << -1 << '\n';
      else cout << front() << '\n';
    }
    else{ // back
      if(tail==head) cout << -1 << '\n';
      else cout << back() << '\n';
    }
  }
}
