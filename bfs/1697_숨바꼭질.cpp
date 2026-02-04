#include <iostream>
#include <queue>
using namespace std;

int dist[100002]; //방문 여부 확인 + 소요 시간 저장
int n, k;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  fill (dist, dist+100001, -1); //모든 거리를 -1로 설정 (방문하지 않았음을 의미)

  dist[n] = 0;  // 시작점은 0초 소요
  queue<int> Q;
  Q.push(n);  //큐에 시작점 투입

  while(dist[k] == -1) { //동생을 찾을 때까지
    int cur = Q.front();
    Q.pop(); //현재 위치 꺼내기

    for (int nxt : {cur-1, cur+1, 2*cur}) { //3가지 이동경로
      if (nxt < 0 || nxt > 100000) continue;  
      if (dist[nxt] != -1) continue;  //중복 방문 방지

      //거리 갱신 
      dist[nxt] = dist[cur] + 1;
      Q.push(nxt);
    }
  }
  cout << dist[k];
}