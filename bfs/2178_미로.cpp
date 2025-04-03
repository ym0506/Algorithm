#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define X first  // pair.first를 X로 간단히 접근하기 위한 매크로
#define Y second // pair.second를 Y로 간단히 접근하기 위한 매크로

// 최대 102x102 크기의 전역 배열: 격자(board)와 거리(dist) 저장
string board[102];  // 각 요소가 한 행(문자열)을 나타냄
int dist[102][102]; // (행, 열) 각 위치까지의 최단 거리를 저장할 2차원 배열

// n = 행 수, m = 열 수
int n, m;

// dx, dy: 상하좌우 네 방향으로 이동하기 위한 배열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // n줄을 읽어서 board[i]에 저장 (각 줄은 문자열)
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    // dist 배열을 -1로 초기화하여 미방문 상태로 설정
    for (int i = 0; i < n; i++)
    {
        fill(dist[i], dist[i] + m, -1);
    }

    // BFS를 위한 큐를 준비하고 시작 위치를 설정
    queue<pair<int, int>> Q;
    Q.push({0, 0}); // (0,0)을 큐에 삽입 (좌측 상단이 시작점)
    dist[0][0] = 0; // 시작점은 거리 0

    // BFS 루프: 큐가 빌 때까지 계속 탐색
    while (!Q.empty())
    {
        // 큐의 맨 앞 원소(현재 위치)를 꺼냄
        auto cur = Q.front();
        Q.pop();

        // 현재 위치 cur에서 네 방향(상하좌우) 확인
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir]; // 이동 후 행 인덱스
            int ny = cur.Y + dy[dir]; // 이동 후 열 인덱스

            // a) 격자 범위를 벗어나면 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }

            // b) 이미 방문했거나(dist[nx][ny] != -1)
            //    보드가 '1'이 아니라면(통로가 아니면) 무시
            if (dist[nx][ny] != -1 || board[nx][ny] != '1')
            {
                continue;
            }

            // c) 미방문이면서 '1'인 칸이면, 거리 갱신 후 큐에 삽입
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    // 6) 맨 아래 오른쪽 칸까지의 최단 거리 + 1을 출력
    //    (문제에 따라 칸 수를 세야 할 때 +1이 필요한 경우가 있음)
    cout << dist[n - 1][m - 1] + 1 << "\n";

    return 0;
}
