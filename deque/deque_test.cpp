#include <iostream>
#include <deque>
using namespace std;

const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;


void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

void test() {
    push_front(10);
    cout << front() << '\n';
    push_back(50);
    push_front(20);
    push_back(70);
    cout << back() << '\n'; // 70
    pop_back();
    cout << back() << '\n'; // 50
    pop_front();
    cout << front() << '\n'; // 10
    push_back(100);
    push_front(30);
    cout << back() << '\n'; // 100
    pop_back();
    cout << back() << '\n'; // 50
    pop_front();
    cout << front() << '\n'; // 20
}
    

int main(void) {
    test();
}