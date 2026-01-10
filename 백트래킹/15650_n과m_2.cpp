#include <iostream>

using namespace std;

int n,m;
int arr[40];

// k: 현재까지 선택한 숫자 개수
void func(int k) {
    // 목표한 M개를 모두 골랐을 때
    if (k == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int st = 1;
    if (k != 0) st = arr[k-1] + 1;  // 바로 직전에 고른 수보다 1 큰 수부터 시작 (오름차순)

    for (int i = st; i <= n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    func(0);
}