#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

char board[101][101];
bool vis[101][101];
int n;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

// (i,j)와 연결된 같은 색의 모든 영역을 찾아 vis = true로 칠하는 함수
void bfs (int i, int j) {
    queue<pair<int, int> > Q;
    Q.push({i, j});
    vis[i][j] = 1;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;   //범위 밖일 경우 넘어감

            if (vis[nx][ny] == 1 || board[i][j] != board[nx][ny]) continue;   //이미 방문한 칸이거나 같은 색이 아닐 경우 넘어감

            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

// 전체 board를 돌며 총 구역이 몇 개인지 세는 함수
int area() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {    //아직 방문 안함
                cnt++;  // 새로운 구역으로 인정하고
                bfs(i,j);   //이 땅과 연결된 모든 곳을 방문처리
            } 
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int not_g = area(); //적록색약이 아닌 사람

    //2차 실행을 위해 방문 기록 초기화
    for (int i = 0; i < n; i++) {
        fill (vis[i], vis[i] + n, false);
    }

    //적록색약의 시각으로 G를 R로 변경
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') 
                board[i][j] = 'R';
        }
    }

    int is_g = area();  //2차 실행
    cout << not_g << " " << is_g;
    return 0;
}