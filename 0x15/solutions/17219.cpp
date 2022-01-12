// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/****************
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    unordered_map<string , string> hash;
    string addr, password;
    while (n--) {
        cin >> addr >> password;
        hash[addr] = password;
    }
    while (m --) {
        cin >> addr;
        cout << hash[addr] << '\n';
    }
}