#include <iostream>
using namespace std;

#define X first
#define Y second

string board[1002];
int fire_time[1002][1002]; // 불의 전파 시간
int jihun_time[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    fill(fire_time[i], fire_time[i] + m, -1);
    fill(jihun_time[i], jihun_time[i] + m, -1);
  }

  for (int i = 0; i < n; i++)
    cin >> board[i];

  queue<pair<int, int>> Q_fire;
  queue<pair<int, int>> Q_jihun;

  // 시작점 파싱
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'F') {
        Q_fire.push({i,j});
        fire_time[i][j] = 0;  //불 시작점 0초
      }
      if (board[i][j] = 'J') {
        Q_jihun.push({i,j});
        jihun_time[i][j] = 0;
      }
    }
  }

  // 불에 대한 BFS
  while (!Q_fire.empty()) {
    auto cur = Q_fire.front();
    Q_fire.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (fire_time[nx][ny] >= 0 || board[ny][ny] == '#') continue;

      fire_time[nx][ny] = fire_time[cur.X][cur.Y] + 1;
      Q_fire.push({nx,ny});
    }
  }
  

  // 지훈이에 대한 BFS
  while (!Q_jihun.empty()) {
    auto cur = Q_jihun.front();
    Q_jihun.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) //범위를 벗어나면 탈출
        cout << jihun_time[cur.X][cur.Y] + 1;
        return 0;

        if (jihun_time[nx][ny] >= 0 || board[nx][ny] == '#') continue; //이미 방문했거나 벽
        if (fire_time[nx][ny] != -1 && fire_time[nx][ny] <= jihun_time[cur.X][cur.Y] + 1) continue;
        // 불이 먼저(동시에) 도착하느냐?
        // fire_time이 -1인 경우(불이 아예 안닿는 곳)는 비교하지 않고 이동

        jihun_time[nx][ny] = jihun_time[cur.X][cur.Y] + 1;
        Q_jihun.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.
}