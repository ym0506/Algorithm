#include <iostream>
using namespace std;

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int board[103][103][103];
int dist[103][103][103];    //방문 여부 및 걸린 시간
queue<tuple<int, int, int>> Q;

int m, n, h;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i =0 ; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int tmp;
                cin >> tmp;
                board[i][j][k] = tmp;

                //익은 토마토는 시작점이므로 큐에 삽입
                if (tmp == 1) Q.push({i,j,k});

                // 안 익은 토마토는 -1로 방문안함 표시
                if (tmp == 0) dist[i][j][k] = -1;
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;

        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (dist[nx][ny][nz] >= 0) continue;

            dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
            Q.push({nx,ny,nz});
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (dist[i][j][k] == -1) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}