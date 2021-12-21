// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : - connieya
// http://boj.kr/****************
#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[10];
int num[10];
bool visited[10];

void func(int L) {
    if (L == m) {
        for (int i = 0; i < m; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp =0; // 중복 수열인지 확인 하기 위해 필요한 임시 변수
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && tmp != num[i]){  // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
            visited[i] = true;
            arr[L] = num[i];
            tmp = arr[L];
            func(L + 1);
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
    func(0);
}