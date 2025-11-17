#include <iostream>
#include <queue>
#include <string>

#define X first 
#define Y second 

using namespace std;

int board[1002][1002];
int dist[1002][1002];   //각 토마토가 익는데 걸리는 일수를 저장 (방문 여부 확인 겸)
int n, m;   //n 행(세로), m 열(가로)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    queue<pair<int, int>> Q;

    // 초기 상태 세팅
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            //익은 토마토(1)는 시작점이므로 큐에 바로 푸쉬
            // dist[i][j]는 전역변수라 이미 0임(0일차)
            if (board[i][j] == 1)
                Q.push({i,j});

            // 익지 않은 토마토(0)는 아직 방문하지 않았음을 표시 (-1)
            if (board[i][j] == 0)
                dist[i][j] = -1;
        }
    }
    
    //BFS 수행
    while (!Q.empty()) {
        auto cur = Q.front();   //현재 익은 토마토 꺼내기
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            //격자 범위를 벗어나면 스킵
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            //이미 익었거나 (-1이 아님), 벽 (0)이면 스킵
            // board가 -1(벽)일 때 dist는 0이므로 여기서 걸러짐
            if (dist[nx][ny] >= 0) continue;

            //전파 : 일수 증가 및 큐에 추가
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // BFS가 끝났는데도 -1이 남아있다면, 도달 불가능한 토마토가 있다는 뜻
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}