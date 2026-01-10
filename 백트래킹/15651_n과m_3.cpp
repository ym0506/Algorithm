#include <iostream>
using namespace std;


int n, m;
int arr[40];


void func (int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int st = 0; 
    for (int i = 1; i <= n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    func(0);
}