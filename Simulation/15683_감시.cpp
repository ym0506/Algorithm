#include <iostream>

using namespace std;

int n, m;
int board[10][10];
int temp[10][10];

// cctv 5종류
// 1: 한 방향
// 2: 양쪽 방향
// 3: 직각 방향
// 4: 세 방향
// 5: 네 방향

// 6은 벽
// 0은 빈칸
// 1~5는 cctv


void func

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    cout << result;
}