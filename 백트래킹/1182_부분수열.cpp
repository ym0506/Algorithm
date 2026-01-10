#include <iostream>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;

// cur: 현재 내가 결정을 내려야 할 원소의 인덱스
// tot: 지금까지 선택한 원소들의 합
void func(int cur, int tot) {
    // 더 이상 고려할 원소가 없을 때 (트리 바닥)
    if (cur == n) {
        if (tot == s) cnt++;    // 지금까지의 합이 목표값 s와 같다면 카운트
        return;
    }

    // 가지치기 왼쪽: 현재원소 arr[cur] 선택 x
    // tot 유지한 채 다음(cur + 1로 넘어감
    func(cur+1, tot);

    // 가지치기 오른쪽: 현재 원소 선택
    // 합에 현재 값으 ㄹ더하고 , 다음으로
    func(cur+1, tot+arr[cur]);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> arr[i];

    func(0,0);  // 0번 인덱스부터 시작, 현재 합 0

    // S가 0일 때, 아무것도 선택하지 않은 공집합(0)도 카운트 하기에
    // 문제에서 크기가 양수인 부분수열만 원하므로 1을 빼줌
    if (s == 0) cnt--;

    cout << cnt;
}