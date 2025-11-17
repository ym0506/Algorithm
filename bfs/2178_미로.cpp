#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define X first  
#define Y second 

string board[102];  //미로 지도
int dist[102][102]; //방문 여부 확인 + 시작점으로부터 거리 저장
int n, m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> board[i];

    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + m, -1);

    queue<pair<int,int>> Q;

    //시작점 세팅
    Q.push({0,0});
    dist[0][0] = 0;
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop(); 
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //맵 밖으로 나가는지?
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; //이미 방문했거나 벽이거나

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1] + 1;
    //시작과 끝 칸도 포함하므로 거리값 + 1
}
