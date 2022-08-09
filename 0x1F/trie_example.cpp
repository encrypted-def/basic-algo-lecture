#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];
int nxt[MX][26];

int c2i(char c){
  return c - 'a';
}

void insert(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = true;
}

bool find(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return false;
    cur = nxt[cur][c2i(c)];
  }
  return chk[cur];
}

void erase(string& s){
  int cur = ROOT;
  for(auto c : s){
    if(nxt[cur][c2i(c)] == -1)
      return ;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = false;
}

void test(){
  string insert1 = "apple";
  insert(insert1);
  string insert2 = "apply";
  insert(insert2);
  string insert3 = "black";
  insert(insert3);
  string insert4 = "ban";
  insert(insert4);
  string insert5 = "banana";
  insert(insert5);

  string find1 = "ban";
  cout << find(find1) << '\n'; // 1
  string find2 = "base";
  cout << find(find2) << '\n'; // 0
  string find3 = "app";
  cout << find(find3) << '\n'; // 0
  
  string erase1 = "banana";
  erase(erase1);
  string erase2 = "talk";
  erase(erase2);
  string erase3 = "apply";
  erase(erase3);
  
  string find4 = "ban";
  cout << find(find4) << '\n'; // 1
  string find5 = "apply";
  cout << find(find5) << '\n'; // 0  
}

int main(void){
  for(int i = 0; i < MX; i++)
    fill(nxt[i], nxt[i]+26, -1);
  test();
}
