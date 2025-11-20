#include <iostream>

using namespace std;

#define X first
#define Y second

int board[51][51];  //배추밭 (1: 배추, 0: 빈 땅)
bool vis[51][51];   //방문 기록 (true: 지렁이가 이미 훑고 감, false: 아직)
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m, n, k;    // M(가로), N(세로), K(배추 개수)
queue <pair<int,int >> q;   //BFS를 위한 방문 예정지 목록


// (x,y) 와 연결된 모든 배추 덩어리를 방문(vis) 처리하는 함수
void bfs (int x, int y) {
    vis[x][y] = true;   //탐색 시작점(x,y)를 방문 완료로 표시
    q.push({x,y});  // 방문 예정 목록(큐)에 시작점 추가

    // 아직 방문할 곳이 남아있다면
    while(!q.empty()) {
        auto cur = q.front(); q.pop();  //큐에서 현재 탐색 기준점 꺼냄

        //현재 위치에서 4방향 확인
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            // 밭의 경계 벗어나는지
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            //이미 방문했거나 배추가 없는 땅인지
            if (vis[nx][ny] || board[nx][ny] != 1) continue;

            // *큐에 넣기 전에 방문 표시를 해야 중복으로 큐에 삽입되는 것을 막음
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;

        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }

        int res = 0;    //필요한 지렁이 수 (배추 덩어리 수)

        // N x M 을 순회하며 아직 방문 안 한 배추를 찾음
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                //(i,j)에 배추가 있고(1) + 아직 방문 x
                if (board[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j);  //그곳을 시작점으로 새로운 bfs 탐색 (연결된 모든 배추 방문처리)
                    res++;  //새로운 덩어리 발견했으니 지렁이 추가
                }
            }
        }
        cout << res << "\n";    //이번 테스트 케이스 결과 출력

        //다음 테스트 케이스를 위해 밭(board)과 방문기록(vis) 초기화
        for (int i = 0; i < n; i++)  {
            fill (board[i], board[i] + m, 0); //0으로
            fill (vis[i], vis[i] + m, false);//false로
        }
    }
    return 0;
}