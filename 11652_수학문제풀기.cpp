#include<bits/stdc++.h>
using namespace std;

int n;
map<long long, int> mp;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        mp[x]++;
    }

    long long ans = 0;
    int best = 0;

    for (auto p : mp) {
        if (p.second > best) {
            best = p.second;
            ans = p.first;
        }
    }

    cout << ans << "\n";
    return 0;
}