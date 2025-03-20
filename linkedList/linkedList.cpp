
#include <iostream>
#include <list>

using namespace std;

int main(void) {
    list<int> L = {1,2,3,4,5,6};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    cout << *t << "\n";
    L.push_back(5);
    L.insert(t, 30);
    t++;
    t = L.erase(t);

    cout << *t << "\n";
    for (auto i : L) cout << i << " ";
    cout << "\n";
    for (list<int>::iterator it = L.begin(); it != L.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}