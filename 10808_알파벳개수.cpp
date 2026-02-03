#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[26];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;

    for (char a : str) {
        cnt[a - 'a']++;
    }
    for (int i = 0; i < 26; i++) cout << cnt[i] << "\n";

    return 0;
}