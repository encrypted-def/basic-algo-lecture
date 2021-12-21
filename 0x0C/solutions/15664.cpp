// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : - connieya
// http://boj.kr/****************
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool visited[10];

void func(int L , int start) {
    if (L == m) {
        for (int i = 0; i < m; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp =0;
    for (int i = start; i < n; ++i) {
        if (!visited[i] && tmp != num[i]){
            visited[i] = true;
            arr[L] = num[i];
            tmp = arr[L];
            func(L + 1, i);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num, num + n);
    func(0,0);
}