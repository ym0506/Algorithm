#include <iostream>
#include <deque>
using namespace std;  // 네임스페이스 추가

int main(void) {
  deque<int> DQ;
  
  // 원소 추가
  DQ.push_front(10);  // 10
  DQ.push_back(50);   // 10 50
  DQ.push_front(24);  // 24 10 50
  
  // 현재 내용 출력
  for(auto x : DQ) cout << x << ' ';
  cout << '\n';
  
  cout << DQ.size() << '\n';  // 3
  
  // 비어있는지 확인
  if(DQ.empty()) cout << "DQ is empty\n";
  else cout << "DQ is not empty\n";  // DQ is not empty
  
  // 앞뒤 원소 제거
  DQ.pop_front();  // 10 50
  DQ.pop_back();   // 10
  
  cout << DQ.back() << '\n';  // 10
  
  // 원소 추가 및 접근
  DQ.push_back(72);  // 10 72
  cout << DQ.front() << '\n';  // 10
  DQ.push_back(12);  // 10 72 12
  
  // 인덱스로 수정
  DQ[2] = 17;  // 10 72 17
  
  // 특정 위치에 원소 삽입
  DQ.insert(DQ.begin()+1, 33);  // 10 33 72 17
  DQ.insert(DQ.begin()+4, 60);  // 10 33 72 17 60
  
  // 내용 출력
  for(auto x : DQ) cout << x << ' ';
  cout << '\n';
  
  // 특정 위치 원소 삭제
  DQ.erase(DQ.begin()+3);  // 10 33 72 60
  cout << DQ[3] << '\n';  // 60
  
  // 모든 원소 제거
  DQ.clear();
  
  return 0;
}