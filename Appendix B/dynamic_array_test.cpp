#include <bits/stdc++.h>
using namespace std;

int* arr;
int len = 0; // 실제 데이터가 들어있는 크기
int capacity = 0; // 현재 삽입이 가능한 최대 크기

void init(){
  arr = new int[1];
  capacity = 1;
}

void expand(){

}

void insert(int idx, int num){
  if(???????){
    expand();
  }

  for(int i = len; i > idx; i--)
    arr[i] = arr[i-1];
  arr[idx] = num;
  len++;
}

void printArr(){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "| " << len << ' ' << capacity;
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  insert(0, 10); // 10, len = 1, capacity = 1
  printArr();
  insert(0, 30); // 30 10, len = 2, capacity = 2
  printArr();
  insert(1, 20); // 30 20 10, len = 3, capacity = 4
  printArr();
  insert(3, 40); // 30 20 10 40, len = 4, capacity = 4
  printArr();
  insert(1, 50); // 30 50 20 10 40, len = 5, capacity = 8
  printArr();
  insert(0, 15); // 15 30 50 20 10 40, len = 6, capacity = 8
  printArr();
}

int main(void) {
  init();
  insert_test();
}
