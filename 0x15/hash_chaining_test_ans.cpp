#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int MX = 500005; // 최대 삽입 횟수
int head[M];
int pre[MX];
int nxt[MX];
string key[MX];
int val[MX];
int unused = 0;

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// 키에 대응되는 값을 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k){
  int h = my_hash(k);
  int idx = head[h];
  while(idx != -1){
    if(key[idx] == k) return idx;
    idx = nxt[idx];
  }
  return -1;
}

void insert(string k, int v){
  int idx = find(k);
  if(idx != -1){
    val[idx] = v;
    return;
  }
  int h = my_hash(k);
  key[unused] = k;
  val[unused] = v;
  if(head[h] != -1){
    nxt[unused] = head[h];
    pre[head[h]] = unused;
  }
  head[h] = unused;
  unused++;
}

void erase(string k){
  int idx = find(k);
  if(idx == -1) return;
  if(pre[idx] != -1) nxt[pre[idx]] = nxt[idx];
  if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
  int h = my_hash(k);
  if(head[h] == idx) head[h] = nxt[idx];
}

void test(){
  insert("orange", 724); // ("orange", 724)
  insert("melon", 20); // ("orange", 724), ("melon", 20)
  assert(val[find("melon")] == 20);
  insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
  insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(val[find("banana")] == 52);
  assert(val[find("orange")] == 100);
  erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(find("orange") == -1);
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
  assert(val[find("orange")] == 15);
  insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
  insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
  insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
  assert(val[find("cherry")] == 27);
  erase("xxxxxxx");
  assert(find("xxxxxxx") == -1);
  assert(val[find("apple")] == 36);
  assert(val[find("melon")] == 20);
  assert(val[find("banana")] == 52);
  assert(val[find("cherry")] == 27);
  assert(val[find("orange")] == 701);
  assert(val[find("lemon")] == 6);  
  cout << "good!\n";  
}

int main(){
  fill(head, head+M, -1);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  test();
}