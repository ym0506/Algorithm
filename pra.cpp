#include<bits/stdc++.h>
using namespace std;

const int max_n = 52;
int a[max_n][max_n], visited[max_n][max_n], m, n, t, k;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
   cin >> t;
   cin >> m >> n >> k;

   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
         a[i][j] = 0;
      }
   }

   for (int i = 0; i < k; i++) {
      cin >> m >> n;
      a[m][n] = 1;
   }

   while (t--) {
      int cnt = 0;
      queue<pair<int, int>> q;
      visited

      for (int i = 0; i < 4; i++) {
         int ny = y + dy[i];
         int nx = x + dx[i];

         if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
         if (a[ny][nx] == 0 || visited[ny][nx]) continue;

         q.push({ ny, nx });
         visited[ny][nx] = 1;
         cnt++;
      }
   }
}