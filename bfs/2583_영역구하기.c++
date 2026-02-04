#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define X first
#define Y second

int board[102][102];
int vis[102][102];
int m,n,k;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<int> ans;

int main() {

    cin >> m >> n >> k;

    while(k--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int row = y1; row < y2; row++) {
            for (int col = x1; col < x2; col++) {
                board[row][col] = 1;
            }
        }
    }

    queue<pair<int, int>> Q;
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 || vis[i][j]) continue;

            int width = 1;
            vis[i][j] = 1;
            Q.push({ i, j });
            count++;

            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                    if (board[nx][ny] == 1 || vis[nx][ny]) continue;

                    vis[nx][ny] = 1;
                    Q.push({ nx, ny });
                    width++;
                }
            }
            ans.push_back(width);
        }
    }
    sort(ans.begin(), ans.end());

    cout << count << '\n';

    for (int i : ans)
        cout << i << ' ';

    return 0;
}

// count++, 크기 width 리스트
// 1부터 bfs돌려 크기 리스트