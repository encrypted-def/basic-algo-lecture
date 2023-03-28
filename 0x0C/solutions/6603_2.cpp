#include <bits/stdc++.h>
using namespace std;

int k, input[20], arr[10], isUsed[20];

void func(int cnt, int cur) {
    if(cnt == 6) {
        for(int i = 0; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int temp = 0;
    for(int i = cur; i < k; i++) {
        if(!isUsed[i] && temp != input[i]) {
            arr[cnt] = input[i];
            isUsed[i] = 1;
            temp = arr[cnt];
            func(cnt+1, i+1);
            isUsed[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> k;
        if(k == 0) break;
        for(int i = 0; i < k; i++) cin >> input[i];
        func(0, 0);
        cout << '\n';
    }
}
