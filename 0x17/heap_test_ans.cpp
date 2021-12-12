#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
  heap[++sz] = x;
  int idx = sz;
  while(idx != 1){
    int par = idx/2;
    if(heap[par] <= heap[idx]) break;
    swap(heap[par], heap[idx]);
    idx = par;
  }
}

int top(){
  return heap[1];
}

void pop(){
  heap[1] = heap[sz--];
  int idx = 1;
  // 왼쪽 자식의 인덱스(=2*idx)가 size보다 크면 idx는 리프
  while(2*idx <= sz){
    int lc = 2*idx, rc = 2*idx+1; // 왼쪽 자식, 오른쪽 자식
    int min_child = lc; // 두 자식 중 작은 인덱스를 담을 예정
    if(rc <= sz && heap[rc] < heap[lc])
      min_child = rc;
    if(heap[idx] <= heap[min_child]) break;
    swap(heap[idx],heap[min_child]);
    idx = min_child;
  }  
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(void){
  test();
}